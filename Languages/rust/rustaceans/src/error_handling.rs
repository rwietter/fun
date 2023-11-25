fn error_handling() {
    // ------------ panic ------------
    // panic!("error!");

    // ------------ Result ------------
    let x: Result<i32, &str> = Ok(-3);
    let y: Result<i32, &str> = Err("Some error message");
    match x {
        Ok(i) => println!("x is {}", i),
        Err(e) => println!("Error: {}", e),
    }
    match y {
        Ok(i) => println!("x is {}", i),
        Err(e) => println!("Error: {}", e),
    }

    // ------------ Option ------------
    let x = 3.0;
    let y = 2.0;
    let result: Option<f64> = if y != 0.0 { Some(x / y) } else { None };
    println!("{:?}", result);
    match result {
        Some(z) => println!("{}/{}={}", x, y, z),
        None => println!("Cannot divide {} by {}", x, y),
    }

    // ------------ unwrap ------------
    let x = 3.0;
    let y = 2.0;
    let result: Option<f64> = if y != 0.0 { Some(x / y) } else { None };
    println!("{:?}", result);
    match result {
        Some(z) => println!("{}/{}={}", x, y, z),
        None => println!("Cannot divide {} by {}", x, y),
    }
    println!("{:?}", result.unwrap());

    // ------------ expect ------------
    let x = 3.0;
    let y = 2.0;
    let result: Option<f64> = if y != 0.0 { Some(x / y) } else { None };
    println!("{:?}", result);
    match result {
        Some(z) => println!("{}/{}={}", x, y, z),
        None => println!("Cannot divide {} by {}", x, y),
    }
    println!("{:?}", result)
}
