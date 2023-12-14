fn extract_number(line: &str) -> i32 {
    let digits: Vec<&str> = line
        .split(|c: char| !c.is_alphabetic())
        .filter(|&x| !x.is_empty())
        .collect();
    let mut number = String::new();

    println!("{:?}", digits);

    for digit in digits {
        match digit {
            "one" => number.push('1'),
            "two" => number.push('2'),
            "three" => number.push('3'),
            "four" => number.push('4'),
            "five" => number.push('5'),
            "six" => number.push('6'),
            "seven" => number.push('7'),
            "eight" => number.push('8'),
            "nine" => number.push('9'),
            _ => (),
        }
    }

    let first_char = line.chars().find(|&c| c.is_digit(10)).unwrap();
    let last_char = line.chars().rev().find(|&c| c.is_digit(10)).unwrap();

    number.push(first_char);
    number.push(last_char);

    number.parse().unwrap()
}

pub fn callibration() {
    let input = "two1nine abcone2threexyz four3five six7eight nine10nine";

    let sum: i32 = input.lines().map(|line| extract_number(line)).sum();
    println!("The sum of all calibration values is: {}", sum);
}
