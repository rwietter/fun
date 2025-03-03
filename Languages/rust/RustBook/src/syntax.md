# Variables

## Declaration

```rust
let x = 5;
```

### Type Annotation

```rust
let x: i32 = 5;
const MAX_POINTS: u32 = 100_000_000; // rust permite usar `_` para separar os dígitos
```

### Mutability

As variáveis ​​são imutáveis ​​por padrão. Para tornar uma variável mutável, use a palavra-chave `mut`.

```rust
let x = 5;
x = 6; // error: cannot assign twice to immutable variable `x`
```

```rust
let mut x = 5;
x = 6; // ok
```

### Constants

As constantes são sempre imutáveis. Para declarar uma constante, use a palavra-chave `const` e o tipo deve ser explicitamente anotado. Ela também não pode ser redeclarada nem receber reatribuições. O Rust não aloca memória para armazenar o valor de uma constante. Em vez disso, o valor é colocado no código compilado em tempo de compilação como hard-coded. 

```rust
const MAX_POINTS: u32 = 100_000;
```

### Shadowing

As variáveis ​​podem ser sombreadas usando o mesmo nome e repetindo a palavra-chave `let`.

```rust
let x = 5;
let x = x + 1;
let x = x * 2;
println!("The value of x is: {}", x); // The value of x is: 12
```

---

## Types

### Data Types

- Slices (variable length): `[1, 2, 3][..]`
- Strings (UTF-8 encoded): `"Hello, world!"`
- Structs (custom types): `struct User { name: String, email: String, sign_in_count: u64, active: bool }`
- Enums (custom types): `enum IpAddrKind { V4, V6 }`
- Option (custom type): `enum Option<T> { Some(T), None }`
- Result (custom type): `enum Result<T, E> { Ok(T), Err(E) }`
- Functions: `fn foo(x: i32) -> i32 { x }`
- Traits: `trait Foo { fn foo(&self); }`
- Lifetimes: `'a`
- Generics: `struct Foo<T> { bar: T }`
- Unsafe code: `unsafe { ... }`
- Raw pointers: `*const T`, `*mut T`
- References: `&T`, `&mut T`
- Dynamically sized types: `[T]`, `str`
- Never type: `!`
- Macros: `macro_rules! foo { ... }`
- Crates: `extern crate foo;`
- Modules: `mod foo;`
- Crates and modules: `crate::foo::bar;`

### Scalar Types

- Integers: `u8`, `i8`, `u16`, `i16`, `u32`, `i32`, `u64`, `i64`, `u128`, `i128` (the `u` means unsigned, and the `i` means signed, and the number after it represents the number of bits they take up)
- Floats: `f32`, `f64`
- Boolean: `bool`
- Characters: `char`

#### Integers

- Signed: suporta números negativos e positivos (-, +)
- Unsigned: suporta apenas números positivos, economiza recursos (+)

| Length  | Signed | Unsigned |
| ------- | ------ | -------- |
| 8-bit   | i8     | u8       |
| 16-bit  | i16    | u16      |
| 32-bit  | i32    | u32      |
| 64-bit  | i64    | u64      |
| 128-bit | i128   | u128     |
| arch    | isize  | usize    |

##### Signed (n=bits)

- range: `-2^(n-1)` to `2^(n-1) - 1`
- i8: `-128 to 127` `[-(2⁷) to (2⁷ - 1)]`
- i16: `-32768 to 32767` `[-(2¹⁵) to (2¹⁵ - 1)]`
- i32: `-2147483648 to 2147483647` `[-(2³¹) to (2³¹ - 1)]`
- i64: `-9223372036854775808 to 9223372036854775807` `[-(2⁶³) to (2⁶³ - 1)]`
- i128: `-170141183460469231731687303715884105728 to 170141183460469231731687303715884105727` `[-(2¹²⁷) to (2¹²⁷ - 1)]`
- isize: o tamanho do ponteiro da arquitetura de destino

##### Unsigned (n=bits)

- range: `0` to `2^n - 1`
- u8: `0 to 255` `[(2⁷) to (2⁸ - 1)]`
- u16: `0 to 65535` `[(2¹⁵) to (2¹⁶ - 1)]`
- u32: `0 to 4294967295` `[(2³¹) to (2³² - 1)]`
- u64: `0 to 18446744073709551615` `[(2⁶³) to (2⁶⁴ - 1)]`
- u128: `0 to 340282366920938463463374607431768211455` `[(2¹²⁷) to (2¹²⁸ - 1)]`
- usize: o tamanho do ponteiro da arquitetura de destino

##### Floats

- f32: `1.2E-38 to 3.4E+38`
- f64: `2.3E-308 to 1.2E+308` (double-precision, the default for floating-point types)

```rust
let x = 2.0; // f64
let y: f32 = 3.0; // f32
```

#### Boolean

- `true` or `false`

```rust
let t = true;
let f: bool = false; // with explicit type annotation
```

#### Characters

- `char` é um tipo de caractere Unicode de 4 bytes em tamanho, representado por aspas simples `'`

```rust
let c = 'z';
let z = 'ℤ';
let heart_eyed_cat = '😻';
```

---

### Compound Types

- Tuples (fixed length): `(i32, f64, u8)`
- Arrays (fixed length): `[1, 2, 3]`

#### Tuples

- Tuples podem ter um número arbitrário de elementos
- Não é possível adicionar ou remover elementos de uma tupla uma vez que ela foi criada
- É possível alterar o valor de um elemento de uma tupla usando `mut` do mesmo tipo
- Cada elemento de uma tupla tem um tipo diferente
- Tuples são indexadas a partir de 0

```rust
let tup: (i32, f64, u8) = (500, 6.4, 1);
let (x, y, z) = tup;
println!("The value of y is: {}", y);
println!("The value of x is: {}", x);
println!("The value of z is: {}", z);
```

#### Arrays

- Arrays são semelhantes às tuplas, mas cada elemento deve ter o mesmo tipo
- Arrays são indexados a partir de 0
- Arrays são alocados na memória de forma contígua
- Arrays são de tamanho fixo, não podem crescer ou diminuir de tamanho pois são alocados na stack.

```rust
let a = [1, 2, 3, 4, 5];
let a: [i32; 5] = [1, 2, 3, 4, 5];
let a = [3; 5]; // [3, 3, 3, 3, 3]
let first = a[0];
let second = a[1];
```

- Operações com arrays usando map, filter, reduce (fold)

```rust
fn main() {
    let (b, c, d) = arrays();
    println!("b: {:?}", b);
    println!("c: {:?}", c);
    println!("d: {:?}", d);
}

fn arrays() -> (Vec<i32>, Vec<i32>, i32) {
    let a = [1, 2, 3, 4, 5];
    let b = a.iter().map(|x| x + 5).collect::<Vec<i32>>();
    let c = a.iter().filter(|x: &&i32| *x % 2 == 0).cloned().collect::<Vec<i32>>();
    let d = a.iter().fold(0, |acc, x| acc + x);

    return (b, c, d);
}
```

- Slice

```rust
fn main() {
    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];
    println!("slice: {:?}", slice); // [2, 3]
    let slice = &a[..3]; // [1, 2, 3]
    let slice = &a[3..]; // [4, 5]

    let s = String::from("hello world");
    let hello = &s[0..5];
    println!("hello: {}", hello);
}
```

---

## Scope

O escopo no rust é definido por chaves `{}`. As variáveis ​​são declaradas dentro de um escopo e são válidas apenas dentro desse escopo. Não é permitido variáveis globais.

```rust
fn main() {
  let x = 5; // x comes into scope

  let y = {
    let x = 3;
    x + 1 // y = 4
  };

  fn foo() -> i32 {
    let x = 10; // x comes into scope
    x + 10 // x goes out of scope, returns 20
  } // x goes out of scope

  print!("The value of x is: {}\n", foo()); // x = 20

  println!("The value of y is: {}", y);
  println!("The value of x is: {}", x); // x = 5
  println!("The value of foo is: {}", foo());
}
```