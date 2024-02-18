package main

import (
	"fmt"
	"os"

	"chapter1/chapter"
)

func main() {
	fmt.Println("Hello World")

	var args = os.Args
	fmt.Println("Accessing args: ", args[2])
	fmt.Println("Contiguous subsequence: ", args[1:3])
	fmt.Println("Contiguous subsequence: ", args[1:len(os.Args)])
	fmt.Println("Contiguous subsequence: ", args[1:])
	fmt.Println("Length of args: ", len(args))

	chapter.Pointers()
}
