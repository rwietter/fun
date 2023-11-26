use std::{
    fs::File,
    io::{self, ErrorKind, Read},
};

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
    let f = File::open("/dev/null/.zshrc");

    let file = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("/dev/null/.zshrc") {
                Ok(file_content) => file_content,
                Err(e) => {
                    println!("Problem creating the file: {:?}", e);
                    return ();
                }
            },
            _ => {
                println!("Problem opening the file: {:?}", error);
                return ();
            }
        },
    };

    print!("File: {:?}", file);
}

fn error_handling_closure() {
    let greeting_file = File::open(".zshrc").unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create(".zshrc").unwrap_or_else(|error| {
                panic!("Problem creating the file: {:?}", error);
            })
        } else {
            panic!("Problem opening the file: {:?}", error);
        }
    });
}

fn error_handling_unwrap() {
    // expect() is similar to unwrap(), but it lets us choose the panic!() error message.
    let greeting_file =
        File::open("hello.txt").expect("hello.txt should be included in this project");
}

fn error_propagation() -> Result<String, std::io::Error> {
    let file = File::open("hello.txt");

    let mut username_file = match file {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut username = String::new();

    match username_file.read_to_string(&mut username) {
        Ok(_) => Ok(username),
        Err(e) => Err(e),
    }
}

// A propagação de erros pode ser simplificada com o operador Chaining Method Call (?).
// Podemos usar o operador ? em uma função que retorna Result<T, E>.
fn read_username_from_file() -> Result<String, io::Error> {
    let mut username = String::new();

    let mut username_file = File::open("hello.txt")?;
    username_file.read_to_string(&mut username)?;

    // Alternativamente, podemos encadear os métodos:
    // File::open("hello.txt")?.read_to_string(&mut username)?;

    Ok(username)
}
