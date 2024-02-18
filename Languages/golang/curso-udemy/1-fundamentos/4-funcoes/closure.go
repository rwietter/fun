package main

func closure() func(world string) {
	hello := "Hello"

	fn := func(world string) {
		println(hello, world)
	}

	return fn
}

func main() {
	fn := closure()
	fn("World")
}
