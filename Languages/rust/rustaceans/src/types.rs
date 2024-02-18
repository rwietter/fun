fn types() {
    let x = 5; // x: i32
    let y: i64 = 1234567890; // y: i64
    let z: f32 = 3.141592; // z: f32
    let zero = z as i32; // zero: i32
    let bin = 0b1111_0000; // bin: i32
    let oct = 0o7320_1546; // oct: i32
    let b = true; // b: bool
    let c = 'c'; // c: char
    let s = "hello"; // s: &str
    let s = String::from("hello"); // s: String
    let a = [1, 2, 3]; // a: [i32; 3]
    let v = vec![1, 2, 3]; // v: Vec<i32>
    let tuple = (1, "hello"); // tuple: (i32, &str)
    let (x, y, z) = (1, 2, 3); // x: i32, y: i32, z: i32
    let (x, y) = (1, "hello"); // x: i32, y: &str
    let (x, ..) = (1, 2, 3); // x: i32
    let (.., z) = (1, 2, 3); // z: i32
    let (x, y, ..) = (1, 2, 3); // x: i32, y: i32
    let (x, .., z) = (1, 2, 3); // x: i32, z: i32

    println!("x: {}", x);
}
