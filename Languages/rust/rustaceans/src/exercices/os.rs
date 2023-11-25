use std::fs;

pub fn system() {
    let mut buffer = String::new();
    // let stdin = io::stdin().read_line(&mut buffer);

    if buffer.is_empty() {
        buffer.push_str("/etc/pacman.conf");
    }

    let path = fs::read(buffer).unwrap();
    let content = String::from_utf8(path).unwrap();

    remove_commented_lines(&content);
}

fn remove_commented_lines(s: &String) {
    let mut pacman_conf = String::new();

    for line in s.lines() {
        if line.starts_with("#") || line.is_empty() {
            continue;
        } else {
            pacman_conf.push_str(line);
            pacman_conf.push_str("\n");
        }
    }

    let _ = fs::write("/home/rwietter/test.txt", pacman_conf);
}
