use std::{
    fs,
    io::{prelude::*, BufReader},
    net::{TcpListener, TcpStream},
};

fn main() {
    let listener = TcpListener::bind("127.0.0.1:7878");
    let pkr = Box::new(2);

    let listener = match listener {
        Ok(listener) => listener,
        Err(e) => {
            println!("Failed to bind port 7878: {:?}", e);
            return;
        }
    };

    println!("{}", format!("{pkr:p}"));

    println!("Server started! Listening on port 7878");

    for stream in listener.incoming() {
        let stream = stream.unwrap();
        handle_connection(stream);
    }
}

fn handle_connection(mut stream: TcpStream) {
    let buf_reader = BufReader::new(&mut stream);
    let request_line = buf_reader.lines().next().unwrap().unwrap();

    let (status_line, filename) = if request_line == "GET / HTTP/1.1" {
        ("HTTP/1.1 200 OK", "index.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND", "404.html")
    };

    let html = fs::read_to_string(filename).unwrap();
    let len = html.len();
    let response = format!("{status_line}\r\nContent-Length: {len}\r\n\r\n{html}");
    stream.write_all(response.as_bytes()).unwrap();
}
