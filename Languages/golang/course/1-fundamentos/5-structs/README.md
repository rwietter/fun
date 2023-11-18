# Structs

Em Go, structs são coleções de campos com tipos específicos. São úteis para agrupar dados e formar registros.

```go
package main

import "fmt"

type Vertex struct {
  X int
  Y int
}

func main() {
  fmt.Println(Vertex{1, 2})
}
```

## Structs com ponteiros

Para alterar um campo em uma struct cujo objeto seja passado como parâmetro para uma função, é necessário passar o ponteiro da struct.

```go
package main

import "fmt"

type Vertex struct {
  X int
  Y int
}

func (v *Vertex) changeX() {
  v.X = 10
}

func main() {
  v := Vertex{1, 2}
  fmt.Println(v)
  // Não é necessário passar o ponteiro explicitamente pois o objeto já é referenciado no parâmetro do método
  v.changeX() 
  fmt.Println(v)
}
```
