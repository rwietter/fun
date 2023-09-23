package app

import (
	"log"
	"net"

	"github.com/urfave/cli"
)

func SearchServers(c *cli.Context) error {
	host := c.String("host")

	servers, error := net.LookupNS(host)

	if error != nil {
		log.Fatal(error)
	}

	println("Servers found:")
	for _, server := range servers {
		println(host, ":", server.Host)
	}

	return nil
}
