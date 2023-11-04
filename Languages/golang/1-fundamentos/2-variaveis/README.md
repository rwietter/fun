## Variáveis

A instrução `var` declara uma lista de variáveis, como em listas de argumentos de função, o tipo é o último passado.

A declaração `var` pode estar num pacote ou a nível de função.

```go
package main

import "fmt"

var c, python, java bool // false false false

func main() {
	var i int // 0
	fmt.Println(i, c, python, java) // 0 false false false
}
```

### Variáveis com inicializadores

A declaração `var` pode incluir inicializadores, uma por variável.

Se um inicializador está presente, o tipo pode ser omitido; a variável terá o tipo do inicializador.

```go
package main

import "fmt"

var i, j int = 1, 2

func main() {
	var c, python, java = true, false, "no!"
	fmt.Println(i, j, c, python, java) // 1 2 true false no!
}
```

### Declarações curtas de variáveis

Dentro de uma função a instrução de atribuição curta `:=` pode ser utilizada em lugar de uma declaração `var` com o tipo implícito.

Fora de uma função cada estrutura começa com uma palavra-chave (`var`, `func`, e assim por diante) e não é possível usar o `:=`.

```go
package main

import "fmt"

here := "here" // error because it's outside of a function, use var instead

func main() {
	var i, j int = 1, 2
	k := 3
	c, python, java := true, false, "no!"

	fmt.Println(i, j, k, c, python, java) // 1 2 3 true false no!
}
```

### Valores zero

Variáveis declaradas sem um valor inicial explicitado darão seu valor zero.

O valor zero é:

- `0` para tipos numéricos
- `false` para tipos booleanos
- `""` (string vazia) para strings

```go
package main

import "fmt"

func main() {
	var i int
	var f float64
	var b bool
	var s string
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
}
```

## Constantes

Constantes são declaradas como variáveis, mas com a palavra-chave `const`.

Constantes podem ser sequências de `caracteres`, `booleanos`, ou valores `numéricos`.

Constantes **não** podem ser declaradas usando a sintaxe `:=`.

```go
package main

import "fmt"

const Pi = 3.14

func main() {
	const World = "世界"
	fmt.Println("Hello", World) // Hello 世界
	fmt.Println("Happy", Pi, "Day") // Happy 3.14 Day

	const Truth = true
	fmt.Println("Go rules?", Truth) // Go rules? true
}
```
