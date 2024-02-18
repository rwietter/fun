package main

import (
	"bytes"
	"fmt"
	"os"

	_ "github.com/chzyer/readline"
	shell "github.com/ipfs/go-ipfs-api"
	"github.com/urfave/cli/v2"
)

func main() {
	app := &cli.App{
		Name:                 "ifps",
		Version:              "0.0.1",
		Usage:                "ifps is a simple cli tool for checking ipfs file hash",
		EnableBashCompletion: true,
		HideHelpCommand:      true,
		Suggest:              true,
		Commands: []*cli.Command{
			{
				Usage: "check if content exists in ipfs",
				Aliases: []string{
					"f",
				},
				Action: func(c *cli.Context) error {
					path := c.Args().First()
					if path == "" {
						fmt.Println("please input file path")
						return nil
					}
					file, err := os.Open(path)
					if err != nil {
						fmt.Println(err)
						return nil
					}

					defer file.Close()

					buf := bytes.NewBuffer(nil)

					if _, err := buf.ReadFrom(file); err != nil {
						fmt.Println(err)
						return nil
					}

					hash, err := CheckFileHash(buf.Bytes())

					if err != nil {
						fmt.Println(err)
						return nil
					}

					fmt.Println(hash)
					return nil
				},
			},
		},
	}

	if err := app.Run(os.Args); err != nil {
		panic(err)
	}
}

func CheckFileHash(content []byte) (string, error) {
	sh := shell.NewShell("localhost:5001")

	cid, err := sh.Add(bytes.NewReader(content))

	if err != nil {
		return "", err
	}

	fmt.Println(cid)

	return "", nil
}
