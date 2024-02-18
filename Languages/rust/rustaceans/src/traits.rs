fn traits() {
    // ------------ trait declaration ------------
    trait Foo {
        fn bar(&self);
    }
    struct Baz;
    impl Foo for Baz {
        fn bar(&self) {
            println!("Hello world!");
        }
    }
    let baz = Baz;
    baz.bar(); // prints "Hello world!"
}
