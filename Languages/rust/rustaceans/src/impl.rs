enum Algebraic {
    Unit,
    Single(i32),
    Double(i32, i32),
}

impl Algebraic {
    fn new() -> Algebraic {
        Algebraic::Unit
    }

    fn single(i: i32) -> Algebraic {
        Algebraic::Single(i)
    }

    fn double(i: i32, j: i32) -> Algebraic {
        Algebraic::Double(i, j)
    }
}

fn main() {
    let unit = Algebraic::new();
    let single = Algebraic::single(1);
    let double = Algebraic::double(1, 2);

    match unit {
        Algebraic::Unit => println!("Unit"),
        Algebraic::Single(i) => println!("Single {}", i),
        Algebraic::Double(i, j) => println!("Double {} {}", i, j),
    }
}
