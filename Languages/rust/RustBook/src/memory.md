# Memory management

## Static

Variaveis estáticas são armazenadas no segmento de dados do binário. Elas são inicializadas quando o programa inicia e são válidas para toda a vida útil do programa. Elas não são seguras para threads.

A memória estática tem um tamanho fixo e é alocada no início da execução do programa.

- Performance
- Life time: programa (termina no fim do programa)
- Fixa

```rust
static mut COUNTER: u32 = 0; // maior performance, aloca na memória estática
```

## Stack

Os tipos primitivos como interios, floats, booleans, chars e tuplas são armazenados na pilha. Quando uma variável é declarada, ela é alocada na pilha e quando ela sai de escopo, ela é desalocada da pilha.

- Dinâmica (limite)
- Life time: escopo (termina no return)
- Frame: pilha específica para cada função

```rust
let x = 5; // aloca na pilha
```

## Heap

Os tipos de dados que não sabemos o tamanho em tempo de compilação, como strings, vetores e structs, são armazenados no heap.

- Dinâmica (computer memory limit)
- Life time: escopo (termina no return)
- Não é possível saber o tamanho em tempo de compilação
- Thread safe
- Shared references
- Cleanup: RAII (Resource Acquisition Is Initialization) -> Drop (destructor when goes out of scope)

```rust
fn main() {
    let users = get_users(); // aloca no heap
}
```

---

## Concepts about memory

### Memory leak

Ocorre quando um programa reserva memória, mas não libera essa memória quando não é mais necessária.

```rust
fn main() {
    let mut v = Vec::new();

    for i in 1..100 {
        v.push(i);
    }
}
```

Para resolver esse problema, podemos usar o método `drop` para liberar a memória.

```rust
fn main() {
    let mut v = Vec::new();

    for i in 1..100 {
        v.push(i);
    }

    drop(v);
}
```