package main

import "errors"

type Vertex struct {
	X, Y int16
}

func (v Vertex) abs() (int16, error) {
	if v.X < 0 || v.Y < 0 {
		return 0, errors.New("Negative value")
	}
	return v.X + v.Y, nil
}

func main() {
	v := Vertex{3, 4}
	abs, err := v.abs()

	if err != nil {
		println(err.Error())
		return
	}

	println(abs)

	v = Vertex{-5, -1}

	abs, err = v.abs()

	if err != nil {
		println(err.Error())
		return
	}

	println(abs)
}
