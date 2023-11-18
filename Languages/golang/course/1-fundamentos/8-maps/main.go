package main

import (
	"fmt"
)

func main() {
	user1 := map[string]string{
		"name":     "John",
		"lastname": "Doe",
	}
	fmt.Println(user1["name"])

	// map of maps
	user2 := map[string]map[string]string{
		"user1": {
			"name":     "John",
			"lastname": "Doe",
		},
		"user2": {
			"name":     "Jane",
			"lastname": "Doe",
		},
	}
	fmt.Println(user2)

	// delete a element from map
	delete(user2, "user2")
	fmt.Println(user2)

	// add a element to map
	user2["user3"] = map[string]string{
		"name":     "Mary",
		"lastname": "Doe",
	}
	fmt.Println(user2)
}
