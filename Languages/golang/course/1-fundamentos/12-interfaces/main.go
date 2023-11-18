package main

import (
	"fmt"
	"math"
)

type Retangulo struct {
	altura  float64
	largura float64
}

type Circulo struct {
	raio float64
}

func (r Retangulo) area() float64 {
	return r.altura * r.largura
}

func (c Circulo) area() float64 {
	return math.Pi * math.Pow(c.raio, 2)
}

// This function accepts only Retangulo type
func printAreaStruct(r Retangulo) {
	fmt.Println(r.area())
}

// But this function accepts any type that implements the Forma interface
type Forma interface {
	area() float64
}

func printAreaInterface(r Forma) {
	fmt.Println(r.area())
}

func main() {
	retangulo := Retangulo{10, 15}
	printAreaStruct(retangulo)    // printAreaStruct accepts only Retangulo type
	printAreaInterface(retangulo) // printAreaInterface accepts any type that implements the Forma interface

	circulo := Circulo{10}
	// printAreaStruct(circulo) // error: circulo is not a Retangulo
	printAreaInterface(circulo) // printAreaInterface accepts any type that implements the Forma interface
}
