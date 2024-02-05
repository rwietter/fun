# Tests

Em Rust, os testes unitários são escritos dentro dos módulos que eles testam. Para que os testes não seja compilados para produção, eles devem ser marcados com a anotação `#[cfg(test)]`.

```rust
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_add() {
        assert_eq!(add(2, 3), 5);
    }
}
```

Para executar os testes, execute o comando `cargo test` no terminal.

```bash
cargo test
```

Asserções podem ser feitas com a macro `assert!` ou com a macro `assert_eq!` e `assert_ne!`.

```rust
#[test]
fn test_subtraction() {
    assert_eq!(subtract(5, 3), 2);
    assert_ne!(subtract(5, 3), 4);
}
```

| Macro                     | Descrição                                  |
| ------------------------- | ------------------------------------------ |
| `assert!(expression)`     | Verifica se a expressão é verdadeira       |
| `assert_eq!(left, right)` | Verifica se os dois valores são iguais     |
| `assert_ne!(left, right)` | Verifica se os dois valores são diferentes |

## Ignorando testes

Para ignorar um teste, basta adicionar a anotação `#[ignore]` acima da função de teste.

```rust
#[test]
#[ignore]
fn expensive_test() {
    // código do teste
}
```

## Integration Testing

Os testes de integração são testes que testam a interação entre os módulos. Para criar um teste de integração, crie um arquivo `tests` dentro da pasta `tests` na raiz do projeto.

```bash
touch tests/integration_test.rs
```

```rust
use crate_name;

#[test]
fn test_integration() {
    // Integration test
}
```

## Mocks e Stubs

Mocks e stubs são ferramentas usadas para isolar unidades de trabalho e fornecer entradas e saídas controladas para seus testes. Eles são particularmente úteis quando você deseja testar uma parte específica do seu código sem realmente invocar serviços ou dependências externas.


### Mocks

Mocks são objetos que simulam o comportamento de objetos reais. Eles são mais úteis quando você deseja testar o comportamento de um objeto que depende de outro objeto. Por exemplo, se você tiver um objeto que depende de um objeto de banco de dados, poderá criar um mock do objeto de banco de dados para testar o comportamento do objeto sem realmente acessar o banco de dados.

```rust
use mockito::mock;

let _m = mock("GET", "/hello")
    .with_status(200)
    .with_body("world")
    .create();

let res = reqwest::get(&format!("{}/hello", mockito::server_url())).unwrap();
assert_eq!(res.text().unwrap(), "world");
```

### Stubs

Os stubs, por outro lado, são usados ​​para simular respostas. Eles não imitam comportamentos, mas fornecem respostas pré-determinadas para chamadas de função.

