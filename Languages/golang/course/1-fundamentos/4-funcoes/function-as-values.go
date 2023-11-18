package main

import (
	"fmt"
	"strings"
)

func compute(fn func(str string) string, value string) string {
	return fn(value)
}

func main() {
	hypot := func(str string) string {
		return strings.ToUpper(str)
	}
	fmt.Println(compute(hypot, "golang"))
}
