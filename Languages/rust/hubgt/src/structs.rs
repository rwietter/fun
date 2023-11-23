fn structs() {
    // ------------ struct declaration ------------
    struct Point {
        x: i32,
        y: i32,
    }
    let origin = Point { x: 0, y: 0 }; // origin: Point
    let x = origin.x; // x: i32
    let y = origin.y; // y: i32

    // ------------ struct update syntax ------------
    struct Point3d {
        x: i32,
        y: i32,
        z: i32,
    }
    let mut point = Point3d { x: 0, y: 0, z: 0 }; // point: Point3d
    point = Point3d { y: 1, ..point }; // point: Point3d
    point = Point3d {
        z: 2,
        x: 1,
        ..point
    }; // point: Point3d

    // ------------ tuple structs ------------
    struct Color(i32, i32, i32);
    let black = Color(0, 0, 0); // black: Color
    let r = black.0; // r: i32
    let g = black.1; // g: i32
    let b = black.2; // b: i32

    // ------------ unit structs ------------
    struct EmptyStruct;
    let empty = EmptyStruct;
}
