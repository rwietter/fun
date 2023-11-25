fn methods() {
    // ------------ method declaration ------------
    struct Baz;
    impl Baz {
        fn barz(&self) {
            println!("Hello world!");
        }
    }
    let baz = Baz;
    baz.barz(); // prints "Hello world!"

    // ------------ associated functions ------------
    impl Baz {
        fn bar(&self) {
            println!("Hello world!");
        }
        fn new() -> Baz {
            Baz
        }
    }
    let baz = Baz::new();
    baz.bar(); // prints "Hello world!"
}
