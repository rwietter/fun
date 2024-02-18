package main

func sum(values ...int) int {
	total := 0
	for _, value := range values {
		total += value
	}
	return total
}

func fibonacci(n uint64) uint64 {
	if n <= 1 {
		return n
	}
	return fibonacci(n-1) + fibonacci(n-2)
}

/**
 * A instrução defer adia a execução de uma função até que a função circundante retorne.
 * Os argumentos da chamada adiada são avaliados imediatamente, mas a chamada da função não é executada até que a função circundante retorne.
 */
func main() {
	defer println("Sum is", sum(1, 2, 3, 4, 5))
	println("Fibonacci is", fibonacci(uint64(15)))
}
