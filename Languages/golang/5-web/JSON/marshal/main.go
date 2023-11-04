package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func main() {
	person := Person{Name: "John", Age: 30}

	// Convert struct to JSON
	personJSON := SliceToJSON(person)
	fmt.Println(personJSON)

	// Convert map to JSON
	personMap := map[string]interface{}{
		"name": "John",
		"age":  30,
	}
	personJSON = MapToJson(personMap)
	fmt.Println(personJSON)
}

func SliceToJSON(slice Person) string {
	b, err := json.Marshal(slice)
	if err != nil {
		panic(err)
	}
	return string(b)
}

func MapToJson(m map[string]interface{}) string {
	b, err := json.Marshal(m)
	if err != nil {
		panic(err)
	}
	return string(b)
}
