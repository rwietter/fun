package main

import (
	"errors"
	"fmt"
)

func SomeFunction(v int) (int, error) {
	if v == 1 {
		return 0, errors.New("something went wrong")
	}
	return 1, nil
}

func main() {
	result, err := SomeFunction(1)
	if err != nil {
		// handle error
	}

	fmt.Println(result)
}
