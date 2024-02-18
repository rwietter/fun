package main

type Vertex struct {
	X, Y int16
}

func (v Vertex) abs() int16 {
	return v.X + v.Y
}

func main() {
	v := Vertex{3, 4}
	println(v.abs())
}
