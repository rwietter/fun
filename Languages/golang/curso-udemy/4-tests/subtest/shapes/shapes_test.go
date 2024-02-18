package shapes_test

import (
	"math"
	"subtests/shapes"
	"testing"
)

func TestShaps(t *testing.T) {
	t.Parallel()
	t.Run("Retangulo", func(t *testing.T) {
		retangle := shapes.Retangulo{Altura: 10, Largura: 12}

		got := retangle.Area()
		want := float64(120)

		if got != want {
			t.Errorf("got %.2f want %.2f", got, want)
		}
	})

	t.Run("Circulo", func(t *testing.T) {
		circle := shapes.Circulo{Raio: 10}

		got := circle.Area()
		want := float64(math.Pi * 100)

		if got != want {
			t.Errorf("got %.2f want %.2f", got, want)
		}
	})
}
