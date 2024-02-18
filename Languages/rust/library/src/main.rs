extern crate library;

use library::english::{farewells, greetings};
use library::japanese::{farewells as jp_farewells, greetings as jp_greetings};

fn main() {
    println!("Hello in English: {}", greetings::hello());
    println!("Hello in Japanese: {}", jp_greetings::hello());
    println!("Goodbye in English: {}", farewells::goodbye());
    println!("Goodbye in Japanese: {}", jp_farewells::goodbye());
}
