# Closures

**Fn**: Esse trait permite que a função referencie (mas não mutuamente) as variáveis do ambiente externo (captura de contexto) por referência imutável. Isso significa que uma função marcada com Fn pode apenas ler as variáveis capturadas, sem modificá-las.

**FnMut**: Este trait permite que a função referencie as variáveis do ambiente externo por referência mutável. Ou seja, funções marcadas com FnMut podem modificar as variáveis capturadas.

**FnOnce**: Este trait representa a propriedade de possuir a propriedade (ownership) das variáveis capturadas. Funções marcadas com FnOnce consomem as variáveis do ambiente externo, movendo a propriedade delas para dentro da função. Isso significa que ela não pode ser chamada mais de uma vez, pois após a primeira chamada, as variáveis foram consumidas e não estão mais disponíveis no escopo original.

Por exemplo, ao passar uma closure para um método de alta ordem, como map, filter ou fold, o tipo da closure é importante para determinar como ela interage com as variáveis capturadas.

`String` não implementa a trait `FnMut` e por isso, um dado de `String` tem a propriedade movida e não pode executar mais de uma vez em uma closure.

```rust
fn main() {
    let mut arr = Vec::new();
    let s = String::from("hello");

    let mut c = || {
        arr.push(s);
    };

    c();
    c(); // value is used here after move
}

```