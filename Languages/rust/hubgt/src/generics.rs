fn generics() {
    // ------------ generic function ------------
    fn foo<T>(x: T) -> T {
        x
    }
    let x = foo(1); // x: i32
    let y = foo("hello"); // y: &str

    // ------------ generic struct ------------
    struct Foo<T> {
        x: T,
    }
    let x: Foo<i32> = Foo { x: 5 }; // x: Foo<i32>
    let y: Foo<&str> = Foo { x: "Hello" }; // y: Foo<&str>

    // ------------ generic enum ------------
    enum Bar<T> {
        A(T),
        B(i32),
    }
    let x: Bar<i32> = Bar::A(5); // x: Bar<i32>
    let y: Bar<&str> = Bar::A("Hello"); // y: Bar<&str>
    let z: Bar<i32> = Bar::B(5); // z: Bar<i32>
}
