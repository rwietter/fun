use std::{ops::Add, vec};

fn generics_add<T>(data: &Vec<T>) -> Option<T>
where
    T: Add<Output = T> + Copy,
{
    data.iter().cloned().reduce(|acc, e| acc + e)
}

pub fn entry() {
    let vec: Vec<i32> = vec![1, 2, 3, 4, 5];
    // Passando vec como empréstimo, mas fazendo uma cópia em alterar o vector.
    let result = generics_add(&vec);

    if let Some(result) = result {
        println!("The sum of generic reduce is: {:?}", result);
    }
}

// ------------------------------------------------------------------

struct Point<T, U> {
    x: T,
    y: U,
}

fn struct_generic() {
    let point = Point { x: 23, y: 4.3 };
    let point = Point { x: 2.3, y: 43 };
}

// ------------------------------------------------------------------

enum Truth<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}

// ----------------------- Method Definitions -----------------------

#[derive(Debug)]
struct Pointers<T> {
    x: Vec<T>,
    y: Vec<T>,
}

impl<T> Pointers<T> {
    fn sort(&mut self)
    where
        T: Ord,
    {
        self.x.sort(); // no method named `sort` found for type parameter `T` in the current scope
        self.y.sort(); // no method named `sort` found for type parameter `T` in the current scope
    }
}

pub fn pointers() {
    let mut ptrs = Pointers {
        x: vec![5, 2, 5, 7],
        y: vec![75, 44, 77, 43],
    };

    ptrs.sort();
    println!("Sort pointers: {:?} and {:?}", ptrs.x, ptrs.y);
}
