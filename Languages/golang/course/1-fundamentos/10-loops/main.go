package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 3; i++ {
		fmt.Println(i)
	}

	// for array
	names := []string{"John", "Jane", "Mary"}
	for index, name := range names {
		fmt.Println(index, name)
	}

	// for map
	cars := map[string]map[string]map[string]string{
		"volksvagen": {
			"gol": {
				"color": "red",
				"year":  "2015",
			},
			"fox": {
				"color": "black",
				"year":  "2016",
			},
		},
		"ford": {
			"fiesta": {
				"color": "white",
				"year":  "2017",
			},
		},
		"hiunday": {
			"hb20": {
				"color": "blue",
				"year":  "2018",
			},
		},
	}

	for key, value := range cars["volksvagen"] {
		fmt.Println(key, value["year"])
	}
}
