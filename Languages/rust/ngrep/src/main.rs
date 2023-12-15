use std::{env, error::Error, process};

use ngrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();
    let config: Result<Config<'_>, &str> = Config::build(&args);

    let file_path: &String = match config {
        Ok(config) => config.file_path,
        Err(err) => {
            println!("Problem parsing arguments: {}", err);
            process::exit(1);
        }
    };

    let contents: Result<String, Box<dyn Error>> = ngrep::read_contents(file_path);

    if let Err(err) = contents {
        println!("Application error: {}", err);
        process::exit(1);
    }

    // if let Ok(contents) = run(config.file_path) {
    //     println!("File contents: {}", contents);
    // }

    let contents = contents.unwrap();
    println!("File contents: {}", contents);
}
