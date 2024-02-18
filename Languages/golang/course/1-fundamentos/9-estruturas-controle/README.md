# Estruturas de controle

## If Else

```go
if x > 10 {
    fmt.Println("x é maior que 10")
} else {
    fmt.Println("x é menor ou igual a 10")
}
```

## Switch

```go
switch x {
case 1:
    fmt.Println("x é igual a 1")
case 2:
    fmt.Println("x é igual a 2")
default:
    fmt.Println("x não é igual a 1 nem a 2")
}
```

### Type Assertion

```go
func typeAssertion(value interface{}) {
	if value == nil {
		fmt.Println("value is nil")
		return
	}

	switch result := value.(type) {
	case int:
		fmt.Println("Sum:", result)
	case string:
		fmt.Println("Error:", result)
	}
}
```

## Condicional Assignment

A variável `result` é limitada ao escopo do `if`. Ou seja, ela não é acessível abaixo do bloco `if`.

```go
if result, ok := resultInt.(int); result > 0 && ok {
  fmt.Println("Result is greater than 0")
}
```
