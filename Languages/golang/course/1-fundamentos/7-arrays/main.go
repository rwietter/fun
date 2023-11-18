package main

import "fmt"

func main() {
	var x [5]int
	fmt.Println(x) // [0 0 0 0 0]

	x[3] = 42
	fmt.Println(x)      // [0 0 0 42 0]
	fmt.Println(len(x)) // 5 (tamanho do array)

	// declaração e inicialização de um array
	y := [5]int{1, 2, 3, 4, 5}
	fmt.Println(y) // [1 2 3 4 5]

	// declaração e inicialização de um array sem especificar o tamanho
	z := [...]int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	fmt.Println(z) // [1 2 3 4 5 6 7 8 9]

	// declaração e inicialização de um array multidimensional
	k := [2][3]int{{1, 2, 3}, {4, 5, 6}}
	fmt.Println(k) // [[1 2 3] [4 5 6]]

	// declaração e inicialização de um array multidimensional sem especificar o tamanho
	l := [...][3]int{{1, 2, 3}, {4, 5, 6}}
	fmt.Println(l) // [[1 2 3] [4 5 6]]

	// declaração e inicialização de um array com diferentes tipos de dados
	m := [3]interface{}{"Hello World", 1, true}
	fmt.Println(m) // [Hello World 1 true]

	// cortar um array
	n := m[1:3]
	fmt.Println(n)
}
