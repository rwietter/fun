use std::collections::HashMap;

enum Median {
    Mid(f32),
    Even(u8),
}

fn median(vec: &Vec<u8>) -> Median {
    let len = vec.len();
    let last = *vec.get(len / 2).unwrap();
    println!("len {len}");
    let is_even = if len % 2 == 0 { true } else { false };

    if !is_even {
        Median::Even(last)
    } else {
        let first = *vec.get((len / 2) - 1).unwrap();
        let mid: f32 = (f32::from(first + last)) / 2.0;
        Median::Mid(mid)
    }
}

fn mode(vec: &Vec<u8>) -> Vec<u8> {
    let mut map: HashMap<u8, u8> = HashMap::new();
    for index in vec.iter() {
        let count = map.entry(*index).or_insert(0);
        *count += 1;
    }

    let max_value = map.values().max().unwrap_or(&0);

    let mut mode: Vec<u8> = vec![];
    for (key, value) in map.iter() {
        if value == max_value {
            mode.push(*key);
        }
    }

    mode
}

pub fn median_mode() {
    let mut vec = vec![3, 4, 6, 7, 8, 9, 3, 3, 8, 6, 8];
    vec.sort();
    let median: Median = median(&vec);
    match median {
        Median::Mid(v) => println!("Median Odd: {}", v),
        Median::Even(v) => println!("Median Even: {}", v),
    }
    let mode = mode(&vec);
    println!("Mode: {:?}", mode)
}
