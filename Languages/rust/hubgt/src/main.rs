#![allow(dead_code)]
#![allow(unused_variables)]
mod exercices;
mod slices;

// use slices::slices;
use exercices::os;

fn main() {
    // let mut s = String::from("Hello");
    // change(&mut s);
    os::system()
}

fn change(str: &mut String) {
    (*str).push_str(", World");
}
