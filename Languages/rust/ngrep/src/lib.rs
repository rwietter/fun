use std::error::Error;
use std::fs;

// How Config should store a reference of arg1 and arg2, we use lifetime specifier, because it's unique way to store references in a struct
pub struct Config<'a> {
    pub query: &'a String,
    pub file_path: &'a String,
}

// <'_> is a lifetime elision, it means that the lifetime of the
// reference returned by build is the same as the lifetime
// of the reference to self in Config
impl Config<'_> {
    pub fn build(args: &Vec<String>) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("not enough arguments");
        }

        let query = &args[1];
        let file_path = &args[2];
        Ok(Config { query, file_path })
    }
}

pub fn read_contents(file_path: &String) -> Result<String, Box<dyn Error>> {
    let contents = fs::read_to_string(file_path)?;
    Ok(contents)
}
