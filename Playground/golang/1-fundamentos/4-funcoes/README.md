## Funções

A função pode ter zero ou mais argumentos. O tipo vem após o nome da variável.

```go
package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func main() {
	fmt.Println(add(42, 13))
}
```

### Funções continuação

Quando dois ou mais parâmetros nomeados consecutivos de uma função compartilham o mesmo tipo, você pode omitir o tipo de todos menos o último. Neste exemplo, vamos encurtar

`x int, y int = x, y int`


## Resultados Múltiplos

Uma função pode retornar qualquer número de resultados.

```go
package main

import "fmt"

func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	a, b := swap("hello", "world")
	fmt.Println(a, b)
}
```

## Resultados nomeados

Os resultados de uma função podem ser nomeados. Se forem, eles são tratados como variáveis definidas no topo da função.

```go
func operations(x, y int) (sum, minus int) {
	sum = x + y
	minus = x - y
	return
}
```

## Funções como valores

As funções são valores também. Elas podem ser passadas como argumentos.

```go
package main

import (
	"fmt"
	"math"
)

func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func main() {
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println(hypot(5, 12))

	fmt.Println(compute(hypot))
	fmt.Println(compute(math.Pow))
}
```

## Init

A função init é chamada automaticamente quando o programa é iniciado. Pode-se ter uma função init por arquivo. A função init não pode ser chamada explicitamente, ela é usada para inicializar variáveis e criar setups.

```go
package main

import "fmt"

func init() {
	fmt.Println("init")
}

func main() {
	fmt.Println("main")
}
```
