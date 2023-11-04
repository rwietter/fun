package main

import (
	"fmt"
)

// return multiple values
func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	a, _ := swap("hello", "world") // _ is a blank identifier
	fmt.Println(a)

	// sum is a function variable
	sum := func(a, b int8) int8 {
		return a + b
	}

	fmt.Println(sum(1, 2))
}
