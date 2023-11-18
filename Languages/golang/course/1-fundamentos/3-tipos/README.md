# Tipos básicos

Os tipos básicos de Go são

- `bool`
- `string`

Signed Integers are integers that can be positive or negative. There are six types of signed integers:

- `int`
- `int8`
- `int16`
- `int32`
- `int64`

Unsigned integers are integers that can only be positive. There are two types of unsigned integers:

- `uint`
- `uint8`
- `uint16`
- `uint32`
- `uint64`
- `uintptr`

- `byte` // pseudônimo para uint8

- `rune` // pseudônimo para int32 - representa um ponto de código Unicode

- `float32`
- `float64`

- `complex64`
- `complex128`

- `error` // tipo de erro <nil>

Os tipos `int`, `uint` e `uintptr` são geralmente de `32 bits` em sistemas de `32 bits` e `64 bits` em sistemas de `64 bits`. Quando você precisar de um valor inteiro deverá usar `int`, a menos que tenha um motivo específico para usar um tipo de inteiro com tamanho especificado ou sem sinal.

```go
package main

import (
	"fmt"
	"math/cmplx"
)

var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

func main() {
	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)
}
```

## Conversões de tipo

A expressão `T(v)` converte o valor `v` para o tipo `T`.

Algumas conversões de tipo:

```go
var i int = 42
var f float64 = float64(i)
var u uint = uint(f)

// Ou, de uma forma mais simples:
i := 42
f := float64(i)
u := uint(f)
```

## Inferência de tipo

Ao declarar uma variável, sem especificar o seu tipo (usando `var` sem um tipo ou na sintaxe `:=`), o tipo da variável é inferida a partir do valor do lado direito.

```go
var i int
j := i // j é um int
```

Quando o lado direito contém uma constante numérica não tipificada, a nova variável pode ser um int, float64, ou complex128 dependendo da precisão da constante

```go
i := 42           // int
f := 3.142        // float64
g := 0.867 + 0.5i // complex128
```
