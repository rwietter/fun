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
	person := `[{"name":"John","age":30},{"name":"Jane","age":25}]`

	// Convert JSON to struct
	personStruct := JSONToSlice(person)
	fmt.Println(personStruct)

	// Convert JSON to map
	personMap := JSONToMap(person)
	fmt.Println(personMap)
}

func JSONToSlice(jsonStr string) []Person {
	var person []Person
	err := json.Unmarshal([]byte(jsonStr), &person)

	if err != nil {
		panic(err)
	}
	return person
}

func JSONToMap(jsonStr string) []map[string]interface{} {
	var data []map[string]interface{}
	err := json.Unmarshal([]byte(jsonStr), &data)
	if err != nil {
		fmt.Println("Erro ao decodificar o JSON:", err)
	}
	return data
}
