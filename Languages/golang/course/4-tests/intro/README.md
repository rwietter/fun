### Tests

Arquivos de testes devem ter o nome finalizado com `_test.go`, exemplo: `address_test.go`

#### Funções

As funções precisam ter o nome iniciado com `Test`, exemplo: `func TestAddressType(t *testing.T) {}`

#### Rodando os testes

Rodar via cli `go test ./...`, ele irá rodar todos os testes do projeto.

#### Paralerismo

Testes também podem ser rodados em paralelo, para isso basta adicionar dentro da função `TestMain` `t.Parallel()`, exemplo:

```go{3}
func TestAddressType(t *testing.T) {
	t.Parallel()
	t.Run("should return 'Rua' when address is 'Rua 1'", func(t *testing.T) {})
}
```

### Coverage

Para rodar o coverage do projeto basta rodar o comando `go test ./... -coverprofile=coverage.out`, ele irá gerar um arquivo `coverage.out` na raiz do projeto.

Para visualizar o coverage basta rodar o comando `go tool cover -html=coverage.out`, ele irá abrir uma página no navegador com o coverage do projeto.

