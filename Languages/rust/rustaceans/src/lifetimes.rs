fn lifetimes() {
    // ------------ lifetime elision ------------
    fn foo(x: &i32) -> &i32 {
        x
    }
    let x = 5; // -+ x goes into scope
    {
        let y = &x; // ---+ y goes into scope
        println!("{}", y); // |
    }
    println!("{}", x); // -+ x goes out of scope
}
