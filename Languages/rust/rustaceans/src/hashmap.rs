use std::collections::HashMap;

#[derive(Debug)]
enum Weekday {
    DayString(String),
    DayInt(u8),
}

pub fn hashmap() {
    let mut days_of_week: HashMap<u8, &str> = HashMap::new();
    days_of_week.insert(1, "Monday");
    days_of_week.insert(2, "Tuesday");
    days_of_week.insert(3, "Wednesday");
    days_of_week.insert(4, "Thursday");
    days_of_week.insert(5, "Friday");
    days_of_week.insert(6, "Saturday");
    days_of_week.insert(7, "Sunday");

    println!("Days of week: {:?}", days_of_week.get(&1).unwrap());

    let mut days_of_week: HashMap<u8, Weekday> = HashMap::new();
    days_of_week.insert(1, Weekday::DayString("Monday".to_string()));
    days_of_week.insert(2, Weekday::DayInt(1));

    dbg!(days_of_week);

    // iter_hashmap();
    count_words();
}

pub fn iter_hashmap() {
    let mut days_of_week: HashMap<u8, &str> = HashMap::new();
    days_of_week.insert(1, "Monday");
    days_of_week.insert(2, "Tuesday");
    days_of_week.insert(3, "Wednesday");
    days_of_week.insert(4, "Thursday");
    days_of_week.insert(5, "Friday");
    days_of_week.insert(6, "Saturday");
    days_of_week.insert(7, "Sunday");

    // if key is present, the value will be updated
    days_of_week.insert(1, "MONDAY");

    // Because this, we may need to check if the key is present before insert
    days_of_week.entry(1).or_insert("Monday"); // If key is present, the value will not be updated

    for (key, value) in &days_of_week {
        println!("{}: {}", *key, value);
    }

    // In this case, the ownership of the hashmap is moved to the for loop. So, we can't use the hashmap after the loop.
    // for (key, value) in days_of_week {
    //     println!("{}: {}", key, value);
    // }
}

pub fn count_words() {
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    dbg!("{:?}", map);
}
