#![allow(dead_code)]
#![allow(unused_variables)]
mod chapter_10;
mod chapter_11;
mod contracts;
mod data_structures;
mod error_handling;
mod exercices;
mod hashmap;
mod move_owner;
mod slices;
mod strings;

// use slices::slices;
use exercices::median_mode;

fn largest<T: PartialOrd>(lst: &Vec<T>) -> &T {
    let mut largest = &lst[0];
    for item in lst {
        if item > largest {
            largest = item;
        }
    }
    largest
}

fn main() {
    // let mut s = String::from("Hello");
    // change(&mut s);
    // os::system()
    let vc = vec![1, 4, 2, 1];
    println!("Largest: {}", *largest(&vc));
    data_structures::vector::vectors();
    slices::string_slice();
    strings::forloop();
    hashmap::hashmap();
    error_handling::error_handling();
    median_mode::median_mode();
    contracts::gessing_game();
    move_owner::move_owner();
    chapter_10::generics::pointers();
    chapter_10::traits::summary::summarize();
    chapter_10::lifetimes::lifetimes::lifetimes()
}

fn change(str: &mut String) {
    (*str).push_str(", World");
}
