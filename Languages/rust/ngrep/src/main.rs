use std::{env, error::Error, process};

use ngrep::Config;

fn main() {
  let args = env::args();
  let config: Result<Config, &str> = Config::build(args);

  let config = match config {
    Ok(config) => config,
    Err(err) => {
      eprintln!("Problem parsing arguments: {}", err);
      process::exit(1);
    }
  };

  let contents: Result<String, Box<dyn Error>> = ngrep::read_contents(&config.file_path);

  if let Err(err) = contents {
    eprintln!("Application error: {}", err);
    process::exit(1);
  }

  let contents = contents.unwrap();

  match config.ignore_case {
    true => {
      let search_result = ngrep::search_case_insensitive(&config.query, contents.as_str());
      ngrep::stdout_result(search_result);
    }
    false => {
      let search_result = ngrep::search_case_sensitive(&config.query, contents.as_str());
      ngrep::stdout_result(search_result);
    }
  }
}
