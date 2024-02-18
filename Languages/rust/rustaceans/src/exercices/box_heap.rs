/*
    - Primitive types are coppied by value and adds to the stack.
    - Complex types are coppied by reference and adds to the heap.
    - Box<T> is a smart pointer to a heap allocated value of type T.
    - We can use Box<T> to store primitive data types on the heap instead of the stack.
*/

pub fn box_heap() {
    let some_number = 42;
    add_one(some_number);
    print!("Sum: {some_number}"); // add_one receivs a copy of some_number in stack

    let some_number = Box::new(23); // here some_number is created in the heap.
    add_two(some_number.clone()); // In this case, some_number are created in the heap one copy of some_number is moved to add_two.
    add_one(*some_number); // Here is created a copy of some_number in stack and moved to add_two.
    add_two(some_number); // add_two takes ownership of some_number.
    print!("Sum: {}" /*some_number */, 1); //  Here some_number does not exist anymore

    // We can use references to borrow the value of some_number, instead of moving it.
    let some_number = Box::new(99);
    add_three(&some_number); // add_two takes a reference to some_number
    print!("Sum: {}", some_number); // Now, some_number was borrowed to the add_three function and still exists.
}

fn add_one(x: i32) -> i32 {
    x + 1 // x is coppied by value
}

// Ownership of x is moved to add_two
fn add_two(x: Box<i32>) -> i32 {
    *x + 2 // x is coppied by reference but ownership is moved to add_two
}

fn add_three(x: &i32) -> i32 {
    *x + 3 // x is coppied by reference but the reference is borrowed
}
