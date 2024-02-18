fn enums() {
    // ------------ enum declaration ------------
    enum Direction {
        Up,
        Down,
        Left,
        Right,
    }
    let x = Direction::Up; // x: Direction
    let y = Direction::Down; // y: Direction
    let z = Direction::Left; // z: Direction
    let w = Direction::Right; // w: Direction

    // ------------ enum with data ------------
    enum OptionalI32 {
        AnI32(i32),
        Nothing,
    }
    let x = OptionalI32::AnI32(5); // x: OptionalI32
    let y = OptionalI32::Nothing; // y: OptionalI32

    // ------------ enum with methods ------------
    impl OptionalI32 {
        fn unwrap(self) -> i32 {
            match self {
                OptionalI32::AnI32(i) => i,
                OptionalI32::Nothing => panic!("Called unwrap() on a Nothing value"),
            }
        }
    }
    let x = OptionalI32::AnI32(5);
    let five = x.unwrap(); // five: i32
    let y = OptionalI32::Nothing;
    y.unwrap(); // panics
}
