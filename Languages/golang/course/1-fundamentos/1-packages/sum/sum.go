package sum

func Sum(a, b int) int {
	mult := multiply(a, b)
	return a + b + mult
}
