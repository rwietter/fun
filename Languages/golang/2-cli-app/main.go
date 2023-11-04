package main

import (
	"ipsource/app"
	"log"
	"os"
)

func main() {
	app := app.Setup()

	error := app.Run(os.Args)
	if error != nil {
		log.Fatal(error)
	}
}
