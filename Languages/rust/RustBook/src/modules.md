Lib.rs: A estrutura típica de um arquivo lib.rs pode incluir a definição de módulos, declarações de funções, estruturas de dados e outros elementos que compõem a interface pública da biblioteca, ou seja, coisas compartilhadas entre os módulos. A estrutura de um arquivo lib.rs é a seguinte:

```rust
mod front_of_house;

pub fn eat_at_restaurant() {}

struct Table {}
```

/Bin: o diretório src/bin é um local comum para colocar código executável independente. Ao contrário do diretório src/lib, que é utilizado para organizar o código de bibliotecas, o diretório src/bin é usado para organizar código executável. Cada arquivo Rust no diretório src/bin representa um programa executável separado.
