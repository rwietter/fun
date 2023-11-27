use std::fmt::Display;

pub trait Summary {
    fn summarize_author(&self) -> String;
    // A implementação na trait substitui a implementação da função na Struct.
    // Quando não for criada a implementação na struct, será usado por padrão essa implementação.
    fn summarize(&self) -> String {
        format!("Read more from {} ...", self.summarize_author())
    }
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
    fn summarize_author(&self) -> String {
        format!("{}", self.author)
    }
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
}

// Essa função recebe uma struct que implementa a trair Summary
pub fn notify(summary: &impl Summary) {
    println!("Breaking news! [{}]", summary.summarize())
}

// Generic trait as parameter
pub fn notify_generic<T: Summary>(summary: &T) {
    println!("Breaking news! [{}]", summary.summarize())
}

// Union impl reference traits
pub fn notify_impl_traits(summary: &(impl Summary + Display)) {
    println!("Breaking news! [{}]", summary.summarize())
}

// Union generic traits
pub fn notify_impl_generic_traits<T: Summary + Display>(summary: T) {
    println!("Breaking news! [{}]", summary.summarize())
}

pub fn notify_where_traits<T, U>(summary: T, item: U)
where
    T: Summary + Display,
    U: Display,
{
    println!("Breaking news! [{}]", summary.summarize())
}

pub fn summarize() {
    let tweet = Tweet {
        username: String::from("rwietter"),
        content: String::from("abc"),
        reply: false,
        retweet: false,
    };

    // Uma forma de invocar a implementação
    let tweet_summary = Summary::summarize(&tweet);
    println!("Tweet Summary: [{}]", tweet_summary);

    // Segunda forma de invocar a implementação
    println!("Tweet Summary: [{}]", tweet.summarize());

    // Uso de uma implementação específica
    notify(&tweet);

    // Uso de uma implementação genérica que implementa a trait Summary
    notify_generic(&tweet)
}
