fn expressions() {
    let r = {
        let y = 3;
        y + 1
    };

    // ------------ if-let ------------
    let x = Some(5);
    match x {
        Some(5) => println!("five!"),
        Some(6) => println!("six!"),
        _ => println!("not five or six :("),
    }
}
