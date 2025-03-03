// slices.rs

/* slices are references to contiguous sequences of elements in a collection
 * slices do not have ownership. Slices are immutable by default
*/

pub fn slices() {
    let s = String::from("Hello, World!");
    let word = first_word(&s);
    println!("The first word is: {}", word);
}

fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}

fn array_slices() {
    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];
    assert_eq!(slice, &[2, 3])
}

pub fn string_slice() {
    let st = "Rust is a very cool language";
    let rust = &st[0..4];
    println!("{}", rust);
    // let crash = &st[17..38]; // thread 'main' panicked at src/slices.rs:35:20:
    // println!("{}", crash);
}
