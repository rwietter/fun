package main

import "fmt"

func main() {
	var x int = 10
	var y = &x                             // obtém o endereço de memória da variável x
	fmt.Println("Valor de y:", *y)         // desreferenciação de y (obtém o valor = 10)
	fmt.Println("Valor do ponteiro x:", x) // 10
	*y++                                   // desreferenciação de y (obtém o valor = 10) e incrementa 1
	x++                                    // incrementa 1 em x
	*y--                                   // desreferenciação de y (obtém o valor = 11) e decrementa 1
	fmt.Println("Valor de y:", *y)         // 11
	fmt.Println("Valor do ponteiro x:", x) // 11
	// &: referenciação
	// *: desreferenciamento ou indirecionamento

	arrayPtr()
}

func arrayPtr() {
	var x [3]int = [3]int{1, 2, 3}
	var y = &x[0] // y -> x[0] == 1
	var z = &x[1] // z -> x[1] == 2
	fmt.Printf("%d %d\n", *y, *z)
	y = z                         // y -> z -> x[1] == 2
	fmt.Printf("%d %d\n", *y, *z) // 2 2 (y e z apontam para o mesmo endereço de memória)
}
