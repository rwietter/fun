package app

import (
	"time"

	"github.com/urfave/cli"
)

// retorna uma instancia de cli.App
func Setup() cli.App {
	app := &cli.App{}
	app.Name = "IP Generator"
	app.Usage = "Search for IP addresses"
	app.EnableBashCompletion = true
	app.Version = "0.0.1"
	app.Author = "Maurício Witter - @rwietter - rwietter@zohomail.com"
	app.UsageText = "iptools [commands] --flags[ip, server] host.com.br"
	app.Compiled = time.Now()

	app.Commands = []cli.Command{
		{
			Name:    "ip",
			Usage:   "search for ip addresses from a host",
			Aliases: []string{"i"},
			Flags: []cli.Flag{
				cli.StringFlag{
					Name:     "host",
					Required: true,
				},
			},
			Action: SearchIp,
		},
		{
			Name:    "server",
			Usage:   "search for the name servers of a host",
			Aliases: []string{"s"},
			BashComplete: func(c *cli.Context) {
				println("bash completion")
			},
			Flags: []cli.Flag{
				cli.StringFlag{
					Name:  "host",
					Usage: "host name",
				},
			},
			Action: SearchServers,
		},
	}
	return *app
}
