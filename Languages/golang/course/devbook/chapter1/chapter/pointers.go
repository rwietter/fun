package chapter

import "fmt"

type Person struct {
	name string
	age  int
}

type Persons struct {
	persons *Person
}

func Pointers() {
	var p Persons = Persons{&Person{"John", 30}}

	updatePersonName(&p, "Doe")

	fmt.Println("Name: ", p.persons.name)
}

func updatePersonName(p *Persons, name string) {
	p.persons.name = name
}
