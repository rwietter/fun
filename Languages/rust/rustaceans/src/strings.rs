fn strings() {
    let s1 = String::from("Hello, ");
    let s2 = String::from("World!");
    // let mut s3 = std::ops::Add::add(s1, &s2);
    let mut s3 = s1 + &s2;
    s3.push_str(" I'm a string");
    let s4 = format!("{}-{}", s2, s3); // Does'nt borrow s2 and s3
    println!("{}", s2);
    println!("{}", s3);
}

pub fn forloop() {
    let st = "Rust is a very cool language";

    for s in st.chars() {
        print!("[{s}]");
    }
    println!();
}
