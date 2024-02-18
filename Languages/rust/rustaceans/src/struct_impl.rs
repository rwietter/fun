mod back_of_house {
    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }
}

pub fn eat_at_restaurant() {
    let mut meal = back_of_house::Breakfast::summer("Rye");
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // if we try to create an instance of Breakfast with seasonal_fruit set to peaches, we'll get a compile error
    let meal = back_of_house::Breakfast {
        toast: String::from("Wheat"),
        seasonal_fruit: String::from("peaches"), // error: field `seasonal_fruit` of struct `back_of_house::Breakfast` is private
    };
}
