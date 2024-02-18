# Arrays e Slices

Em Golang o array é uma estrutura de dados que armazena uma coleção de elementos do mesmo tipo. A diferença entre um array e um slice é que o array tem um tamanho fixo e o slice tem um tamanho dinâmico.

## Arrays

Para declarar um array em Golang, usamos a seguinte sintaxe:

```go
var numeros [5]int
```

Para atribuir valores ao array, usamos o seguinte:

```go
numeros[0] = 1
numeros[1] = 2
numeros[2] = 3
```

Para declarar e atribuir valores ao array, usamos a seguinte sintaxe:

```go
numeros := [5]int{1, 2, 3, 4, 5}
```

Para declarar e atribuir valores ao array sem especificar o tamanho, usamos a seguinte sintaxe:

```go
numeros := [...]int{1, 2, 3, 4, 5}
```

Para declarar e atribuir valores ao array sem especificar o tamanho e o tipo, usamos a seguinte sintaxe:

```go
m := [3]interface{}{"Hello World", 1, true}
fmt.Println(m) // [Hello World 1 true]
```

## Slices

Slices são estruturas de dados que armazenam uma coleção de elementos do mesmo tipo. A diferença entre um array e um slice é que o array tem um tamanho fixo e o slice tem um tamanho dinâmico. Outra diferença é que o slice é uma referência ao array, ou seja, quando você cria um slice, você está criando uma referência para um array. Assim, ao referenciar um slice em um array, modificações no array refletirão no slice.
