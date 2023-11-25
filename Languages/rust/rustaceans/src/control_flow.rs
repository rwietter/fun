fn control_flow() {
    // ------------ if/else ------------
    let x = 5;
    if x == 5 {
        println!("x is five!");
    } else if x == 6 {
        println!("x is six!");
    } else {
        println!("x is not five or six :(");
    }

    // ------------ inlined if/else ------------
    let y = if x == 5 { 10 } else { 15 }; // y: i32

    // ------------ Returning from if/else ------------
    let y = if x == 5 {
        10.to_string()
    } else {
        "fifteen".to_string()
    }; // y: String

    // ------------ Option Some/None ------------
    let config_max: Option<i32> = Some(3u8);
    if let Some(max) = config_max {
        println!("The maximum is configured to be {}", max);
    }

    // ------------ loop ------------
    let mut x = 5;
    loop {
        x += x - 3;
        if x % 5 == 0 {
            break;
        }
    }

    // ------------ while ------------
    let mut x = 5;
    while x != 0 {
        x -= 1;
    }

    // ------------ for ------------
    for x in 0..10 {
        println!("{}", x); // x: i32
    }

    // ------------ for and ranges ------------
    for (i, j) in (5..10).enumerate() {
        println!("i = {} and j = {}", i, j);
    }

    // ------------ for and iterators ------------
    let lines = "hello\nworld".lines();
    for (linenumber, line) in lines.enumerate() {
        println!("{}: {}", linenumber, line);
    }

    // label loop
    'outer: loop {
        println!("Entered the outer loop");
        'inner: loop {
            println!("Entered the inner loop");
            break 'outer;
        }
        println!("This point will never be reached");
    }

    // ------------ Returning from loops ------------
    let mut counter = 0;
    let res = loop {
        counter += 1;
        if counter == 10 {
            break x; // break value returns the value of the loop expression
        }
    };
}
