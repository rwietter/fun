# Pacotes

Cada programa Go é composto de pacotes. Programas começam rodando pelo pacote main.

```go
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println("My favorite number is", rand.Intn(10))
}
```
