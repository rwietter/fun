package main

import (
	"fmt"
)

func main() {
	result := func(value string) string {
		return fmt.Sprintf("Hello %s", value)
	}("World")

	fmt.Println(result)
}
