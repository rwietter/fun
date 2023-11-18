package app

import (
	"log"
	"net"

	"github.com/urfave/cli"
)

func SearchIp(c *cli.Context) error {
	host := c.String("host")

	ips, error := net.LookupHost(host)

	if error != nil {
		log.Fatal(error)
	}

	println("IPs found:")
	for _, ip := range ips {
		println(host, ":", ip)
	}

	return nil
}
