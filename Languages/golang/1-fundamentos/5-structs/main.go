package main

import (
	"fmt"
)

type User struct {
	name    string
	age     int8
	cpf     string
	hobbies []string
	address Adress
}

type Adress struct {
	street string
	number int8
}

func main() {
	var user1 User = User{
		name:    "John",
		age:     18,
		cpf:     "123.456.789-00",
		hobbies: []string{"music", "movies"},
		address: Adress{
			street: "Street 1",
			number: 123,
		},
	}

	var user2 User = User{
		name: "Mary",
		age:  20,
		cpf:  "987.654.321-00",
	}
	user2.hobbies = append(user2.hobbies, "games")
	user2.address = Adress{
		street: "Street 2",
		number: 45,
	}

	fmt.Println(user1)
	fmt.Println(user2)
}
