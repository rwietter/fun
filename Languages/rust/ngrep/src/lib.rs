use std::error::Error;
use std::{env, fs};

// How Config should store a reference of arg1 and arg2, we use lifetime specifier, because it's unique way to store references in a struct
pub struct Config<'a> {
  pub query: &'a String,
  pub file_path: &'a String,
  pub ignore_case: bool,
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

    let ignore_case = env::var("IGNORE_CASE").is_ok();

    Ok(Config {
      query,
      file_path,
      ignore_case,
    })
  }
}

pub fn read_contents(file_path: &String) -> Result<String, Box<dyn Error>> {
  let contents = fs::read_to_string(file_path)?;
  Ok(contents)
}

pub fn search_case_sensitive<'a>(query: &'a str, contents: &'a str) -> Option<Vec<&'a str>> {
  let matched_lines: Vec<&str> = contents
    .lines()
    .filter(|line| line.contains(query))
    .collect();

  if matched_lines.is_empty() {
    return None;
  }

  Some(matched_lines)
}

pub fn search_case_insensitive<'a>(query: &'a str, contents: &'a str) -> Option<Vec<&'a str>> {
  let matched_lines: Vec<&str> = contents
    .lines()
    .filter(|line| line.to_lowercase().contains(query.to_lowercase().as_str()))
    .collect();

  if matched_lines.is_empty() {
    return None;
  }

  Some(matched_lines)
}

pub fn stdout_result(result: Option<Vec<&str>>) {
  match result {
    Some(lines) => {
      for line in lines {
        println!("{}", line);
      }
    }
    None => println!("No results found"),
  }
}

#[cfg(test)]
mod tests {
  use super::*;

  #[test]
  fn case_sensitive() {
    let query = "duct";
    let contents = "Rust:\nsafe, fast, productive.\nPick three.\nDuct tape.";

    let expect = vec!["safe, fast, productive."];

    match search_case_sensitive(query, contents) {
      Some(lines) => assert_eq!(expect, lines),
      None => panic!("No results found"),
    }
  }

  #[test]
  fn case_insensitive() {
    let query = "rUsT";
    let contents = "Rust:\nsafe, fast, productive.\nPick three.\nTrust me.";

    match search_case_insensitive(query, contents) {
      Some(lines) => assert_eq!(vec!["Rust:", "Trust me."], lines),
      None => panic!("No results found"),
    }
  }

  #[test]
  fn nothing_found() {
    let query = "tkd";
    let contents = "\
        Rust:
        safe, fast, productive.
        Pick three.";

    match search_case_sensitive(query, contents) {
      Some(lines) => panic!("Don't expect any results, but got {:?}", lines),
      None => (),
    }
  }
}
