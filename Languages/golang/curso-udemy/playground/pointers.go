package main

import "fmt"

type Person struct {
	Name string
	Age  int
}

/*
 * Este método recebe uma cópia do objeto Person. Ou seja, qualquer alteração
 * feita no objeto dentro do método não será refletida no objeto original.
 */
func (p Person) setCopyName() {
	p.Name = "Copy"
}

func (p *Person) setPointerName() {
	p.Name = "Pointer"
}

func main() {
	person := Person{
		Name: "John",
		Age:  30,
	}

	person.setCopyName()
	fmt.Println(person.Name)
	person.setPointerName()
	fmt.Println(person.Name)
}
