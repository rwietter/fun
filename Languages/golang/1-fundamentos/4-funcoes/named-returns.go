package main

import "fmt"

func operations(x, y int) (sum, minus int) {
	sum = x + y
	minus = x - y
	return
}

func main() {
	fmt.Println(operations(1, 2))
}
