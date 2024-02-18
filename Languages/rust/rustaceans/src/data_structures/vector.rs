pub fn vectors() {
    let mut v: Vec<String> = Vec::new();
    let binding = String::from("Not found");
    let one = v.get(1).unwrap_or(&binding);
    println!("The value of one is: {}", one);

    v.push(String::from("Hello"));
    v.push(String::from("World"));
    v.push(String::from("!"));
    println!("The value of v is: {:?}", v);

    let join = v.join(" ");
    println!("The value of join is: {}", join);

    // using macro
    let v2 = vec![1, 2, 3];
    println!("The value of v2 is: {:?}", v2);

    for value in v2 {
        println!("Iter in vector: {}", value)
    }

    let binding = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let numbers_iterator = binding.into_iter();
    let sum = numbers_iterator.reduce(|acc, item| acc + item);

    match sum {
        Some(result) => println!("Sum: {}", result),
        None => println!("The list is empty"),
    }

    println!("Sum is: {:?}", sum); // Output: 15
}
