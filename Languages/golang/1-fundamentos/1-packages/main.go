package main

import (
	"app/sum"
	"fmt"

	"github.com/badoux/checkmail"
)

func main() {
	fmt.Println("Hello World")
	fmt.Println("The sum is", sum.Sum(1, 2))

	result := checkmail.ValidateFormat("@rwietterzohomail.com")
	fmt.Println("The email is", result)
}
