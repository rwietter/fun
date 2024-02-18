package main

import "fmt"

/**
 * o tipo de retorno é interface{} é um tipo que pode conter valores de qualquer tipo.
 */
func sum(x int, y int) interface{} {
	if x < 0 || y < 0 {
		return "Only positive numbers are allowed"
	}
	return x + y
}

/**
 * Ao usar interface{} como tipo de retorno, é necessário fazer uma asserção de tipo para saber qual o tipo de retorno.
 */
func typeAssertion(value interface{}) {
	if value == nil {
		fmt.Println("value is nil")
		return
	}

	switch result := value.(type) {
	case int:
		fmt.Println("Sum:", result)
	case string:
		fmt.Println("Error:", result)
	}
}

func main() {
	resultInt := sum(1, 2)
	typeAssertion(resultInt)

	resultString := sum(-1, 2)
	typeAssertion(resultString)

	// conditional assignment
	// result recebe o valor de resultInt e verifica se o valor é maior que 0
	// e é um valor verdadeiro para então executar o bloco de código.
	if result, ok := resultInt.(int); result > 0 && ok {
		fmt.Println("Result is greater than 0")
	}
}
