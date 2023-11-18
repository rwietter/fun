# Pointers

O operador `&` é usado para obter o endereço de uma variável. Ele retorna o endereço de memória da variável à qual é aplicado. O endereço de memória é representado como um ponteiro na linguagem.

O operador `*` é usado para obter o valor no endereço de memória apontado pelo ponteiro. Se `ptr` é um ponteiro, então `*ptr` é o valor armazenado no endereço de memória apontado por `ptr`. O operador `*` também é chamado de operador de desreferência.

```go
package main

import "fmt"

func main() {
	var va = 5
	var ptr = &va

	fmt.Printf("Address of var: %p\n", &va)
	fmt.Printf("Value of ptr: %p\n", ptr)
	fmt.Printf("Value of var: %d\n", va)
	fmt.Printf("Value of *ptr: %d\n", *ptr)
}
```

```go
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
	// *: desreferenciação
}
```

## Ponteiros e arrays

```go
package main

import "fmt"

func main() {
	var x [3]int = [3]int{1, 2, 3}
	var y = &x[0] // y -> x[0] == 1
	var z = &x[1] // z -> x[1] == 2
	fmt.Printf("%d %d\n", *y, *z)
	y = z                         // y -> z -> x[1] == 2
	fmt.Printf("%d %d\n", *y, *z) // 2 2 (y e z apontam para o mesmo endereço de memória)
}
```
