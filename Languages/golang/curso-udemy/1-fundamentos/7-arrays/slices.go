package main

import "fmt"

func main() {
	slice1 := []int{1, 2, 3, 4, 5}
	fmt.Println(slice1) // [1 2 3 4 5]

	slice1 = append(slice1, 6, 7, 8, 9)

	// Arrays internos são slices que apontam ao array. O criar um slice, ele retorna um pedaço de um array com o tamanho e a capacidade do array.
	slice2 := make([]int, 5, 6)
	fmt.Println(slice2)                         // [0 0]
	fmt.Println("Tamanho:", len(slice2))        // 2
	fmt.Println("Capacibilidade:", cap(slice2)) // 5

	// Podemos "expandir" o slice
	slice2 = append(slice2, 7, 8, 9, 10)
	fmt.Println(slice2)                         // [0 0 3 4 5 6 7 8 9 10]
	fmt.Println("Tamanho:", len(slice2))        // 10
	fmt.Println("Capacibilidade:", cap(slice2)) // 10
}
