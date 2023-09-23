package main

import "fmt"

type Pessoa struct {
	Nome  string
	Idade int
}

func (p *Pessoa) FazAniversario() {
	p.Idade++
}

func (p *Pessoa) SetNome(nome string) {
	p.Nome = nome
}

func (p *Pessoa) SetIdade(idade int) {
	p.Idade = idade
}

func (p *Pessoa) GetNome() string {
	return p.Nome
}

func main() {
	person := Pessoa{"João", 20}
	fmt.Println(person.Nome, person.Idade) // João 20
	person.FazAniversario()
	fmt.Println(person.Nome, person.Idade) // João 21

	person.SetNome("Maria")
	person.SetIdade(30)
	fmt.Println(person.GetNome(), person.Idade) // Maria 30
}
