# Iteradores

No Rust, os iteradores são lazy, o que significa que não têm efeito até que você chame métodos que consomem o iterador para utilizá-lo. Por exemplo, a função `map` não faz nada até que você chame um método que consome o iterador, como `collect`.

```rust
fn main() {
    let v1 = vec![1, 2, 3];
    let iter = v1.iter().map(|x| x + 1);
    println!("v1: {:?} | iter: {:?}", v1, iter); // iter: Map { iter: Iter([1, 2, 3])
    
    let v2: Vec<_> = iter.collect();
    println!("v1: {:?} | v2: {:?}", v1, v2); // v2: [2, 3, 4]
}
```

Iteradores com for loops:

```rust
fn main() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    for val in v1_iter {
        println!("Got: {}", val);
    }
}
```

Todos os iteradores implementam uma **Trait** chamada **Iterator** que é definida na biblioteca padrão. A definição da Trait é assim:

```rust
pub trait Iterator {
    type Item;

    fn next(&mut self) -> Option<Self::Item>;

    // methods with default implementations elided
}
```

A Trait Iterator requer apenas que os implementadores definam um método: o método **next**, que retorna um item do iterador por vez envolvido em **Some** e, quando a iteração termina, retorna **None**. Podemos chamar o próximo método diretamente nos iteradores:

```rust
fn main() {
    let v1 = vec![1, 2, 3];

    let mut v1_iter = v1.iter();

    assert_eq!(v1_iter.next(), Some(&1));
    assert_eq!(v1_iter.next(), Some(&2));
    assert_eq!(v1_iter.next(), Some(&3));
    assert_eq!(v1_iter.next(), None);
}
```

> Observe também que os valores que obtemos das chamadas next são referências imutáveis ​​aos valores no vetor. O método iter produz um iterador sobre referências imutáveis. Se quisermos criar um iterador que assuma a propriedade de **v1** e retorne valores próprios, podemos chamar **into_iter** em vez de **iter**. Da mesma forma, se quisermos iterar sobre referências mutáveis, podemos chamar **iter_mut** em vez de **iter**.

## Métodos que consomem o iterador (consuming adaptors)

O método **sum** consome o iterador e chama **next** repetidamente até que ele retorne **None**. Ele adiciona todos os valores juntos e retorna o resultado. Ou seja, **sum** toma a propriedade do iterador e não podemos usá-lo depois de chamar **sum**.

```rust
pub fn main() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    let total: i32 = v1_iter.sum();
    println!("Total: {}", total);
    // println!("v1_iter: {:?}", v1_iter); // borrow of moved value: `v1_iter`
}
```

## Métodos que produzem outros iteradores (Iterator adaptors)

**Iterator adaptors** são métodos definidos na característica Iterador que não consomem o iterador. Em vez disso, eles produzem iteradores diferentes alterando algum aspecto do iterador original.

O **map**, por exemplo, retorna um novo iterador após fazer o mapeamento de cada item para um novo valor usando a closure que passamos a ele. O tipo de iterador produzido pelo **map** implementa a mesma trait Iterator que o iterador que o criou.

```rust
pub fn main() {
    let v = vec![1, 2, 3];
    let result = v.iter().map(|x| x + 1).filter(|x| x > &2);
    println!("Result: {:?}", result);

    let result: Vec<i32> = result.collect();
    println!("Result: {:?}", result);
}
```

Esse código acima não percorre o vetor, mas cria um novo iterador que executa as operações quando for consumido. Para consumir o iterador, podemos chamar o método **collect**. Pra isso, devemos utilizar um método como o **fold** ou **collect** para consumir o iterador e produzir um valor concreto.

## Usando Closures que capturam seu ambiente

Muitos iterator adapters aceitam closures como argumentos e, normalmente, as closures que especificaremos como argumentos para iterator adapters serão closures que capturam seu ambiente.

```rust
#[derive(PartialEq, Debug)]
struct Shoe {
    size: u32,
    style: String,
}

// into_iter takes ownership of v
fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|shoe| shoe.size == shoe_size).collect()
}

fn main() {
    let shoes = vec![
        Shoe {size: 10, style: String::from("sneaker")},
        Shoe {size: 13, style: String::from("sandal")},
        Shoe {size: 10, style: String::from("boot")},
    ];

    let shoe_size = 10;
    let in_my_size = shoes_in_size(shoes, shoe_size);
    println!("in_my_size: {:?}", in_my_size);
    // println!("shoes: {:?}", shoes); // value borrowed here after move
}
```

A função **shoes_in_size** toma posse de um vetor de sapatos e um tamanho de sapato como parâmetros. Ele retorna um vetor contendo apenas sapatos do tamanho especificado. Isso acontece porque o **into_iter** se apropria do ownership do vetor.