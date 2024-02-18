fn functions() {
    // ------------ function declaration ------------
    fn foo(x: i32) -> i32 {
        x
    }
    let x: fn(i32) -> i32 = foo; // x: fn(i32) -> i32

    // ------------ function pointer ------------
    let x: fn(i32) -> i32 = foo; // x: fn(i32) -> i32
    let y = x(5); // y: i32
}
