use std::fs::File;

// ------------ Result ------------
fn result() {
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
}

// ------------ Option ------------
fn option() {
    let x = 3.0;
    let y = 2.0;
    let result: Option<f64> = if y != 0.0 { Some(x / y) } else { None };
    println!("{:?}", result);
    match result {
        Some(z) => println!("{}/{}={}", x, y, z),
        None => println!("Cannot divide {} by {}", x, y),
    }
}

fn panic() {
    // panic!("error!"); // Encerra o programa com uma mensagem de erro;
}

// ------------ Result ------------
pub fn error_handling() {
    let f = File::open("hello.txt");

    let file = match f {
        Ok(file) => file,
        Err(error) => {
            println!("Problem opening the file: {:?}", error);
            return ();
        }
    };

    print!("File: {:?}", file);
}
