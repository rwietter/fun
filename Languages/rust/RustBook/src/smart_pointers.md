# Smart Pointers

No Rust, os smart pointers são uma forma de estrutura de dados que não apenas atua como um ponteiro, mas também incorpora metadados e recursos adicionais. Ao contrário dos ponteiros tradicionais, os smart pointers fornecem funcionalidades adicionais, como reference counting e cleanup.


## Box

O tipo `Box<T>` aloca dados na pilha e aponta para eles na heap. O tamanho de um `Box<T>` é o mesmo que o tamanho de um ponteiro, ou seja, o tamanho de um `Box<T>` não muda com base no tamanho dos dados que ele está armazenando.

```rust
fn main() {
    let x = Box::new(42);
    println!("{}", x);
}
```

## Deref

A trait `Deref` permite que você sobrecarregue o operador `*` para que um valor de um tipo possa ser usado como se fosse um valor de outro tipo. Quando você chama `*x`, o Rust chama a função `deref` por trás dos panos.

## Drop

A trait `Drop` permite que você customize o código que é executado quando um valor sai do escopo. O Rust chama a função `drop` por trás dos panos.

```rust
struct Stuff {
    data: String,
}

fn main() {
    let c = Stuff {
        data: String::from("my stuff"),
    };
    drop(c); // chama a função drop explicitamente
}
```

## Rc

O tipo `Rc<T>` permite que você compartilhe um valor entre vários locais de seu programa, mas ele não permite que você altere o valor. O tipo `Rc<T>` é útil quando você deseja compartilhar dados para leitura, como em um ambiente de thread único.

Rc monitora o número de referências a um valor que determina se um valor ainda está em uso ou não. Se não houver nenhuma referência a um valor, o valor poderá ser limpo sem que nenhuma referência se torne inválida.

```rust
use std::rc::Rc;

#[derive(Debug)]
struct Stuff {
    data: String,
}

fn main() {
    let a = Rc::new(Stuff {
        data: String::from("my stuff"),
    });

    let b = Rc::clone(&a); // cria um novo ponteiro para o mesmo valor

    println!("a: {:?} b: {:?}", a, b);
}
```

## RefCell

O tipo `RefCell<T>` permite que você tenha várias referências mutáveis a um valor, mas o Rust não pode garantir que as regras de empréstimo sejam seguidas em tempo de compilação. Se você violar essas regras, o Rust travará seu programa em tempo de execução.

```rust
use std::cell::RefCell;

fn main() {
    let x = RefCell::new(42);
    let y = x.borrow_mut();
    println!("x: {:?}, y: {}", x, y);
}
```

## Arc

O tipo `Arc<T>` é a versão segura para threads do tipo `Rc<T>`. A única diferença entre `Arc<T>` e `Rc<T>` é que `Arc<T>` é seguro para threads e `Rc<T>` não é.

```rust
use std::sync::Arc;

#[derive(Debug)]
struct Stuff {
    data: String,
}

fn main() {
    let a = Arc::new(Stuff {
        data: String::from("my stuff"),
    });

    let b = Arc::clone(&a); // cria um novo ponteiro para o mesmo valor
    println!("a: {:?} b: {:?}", a, b);
}
```

## Mutex

O tipo `Mutex<T>` é a versão segura para threads do tipo `RefCell<T>`. A única diferença entre `Mutex<T>` e `RefCell<T>` é que `Mutex<T>` é seguro para threads e `RefCell<T>` não é.

```rust
use std::sync::Mutex;

fn main() {
    let m = Mutex::new(5);
    {
        let mut num = m.lock().unwrap(); // retorna um MutexGuard<T>
        *num = 6;
    } // MutexGuard<T> é liberado aqui

    println!("{:?}", m);
}
```

## RwLock

O tipo `RwLock<T>` é a versão segura para threads do tipo `RefCell<T>`. A única diferença entre `RwLock<T>` e `RefCell<T>` é que `RwLock<T>` é seguro para threads e `RefCell<T>` não é.

```rust
use std::sync::RwLock;

fn main() {
    let lock = RwLock::new(5);
    {
        let num = lock.read().unwrap(); // retorna um RwLockReadGuard<T>
        assert_eq!(*num, 5);
    } // RwLockReadGuard<T> é liberado aqui


    {
        let mut num = lock.write().unwrap(); // retorna um RwLockWriteGuard<T>
        *num = 6;
    } // RwLockWriteGuard<T> é liberado aqui

     println!("{:?}", lock);
}
```

## Cow

O tipo `Cow<T>` é uma enumeração que pode ser usada para ter uma propriedade de propriedade ou empréstimo. A enumeração `Cow<T>` é útil quando você deseja ter uma propriedade de propriedade ou empréstimo, mas não sabe qual será o caso até o tempo de execução.

```rust
use std::borrow::Cow;

fn main() {
    let mut cow = Cow::from("foo");
    println!("{}", cow);
    assert_eq!(cow, Cow::Borrowed("foo"));

    cow.to_mut().push_str("bar");
    println!("{}", cow);
    assert_eq!(cow, Cow::Borrowed("foobar"));
}
```
