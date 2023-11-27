pub trait Summary {
    // fn summarize(&self) -> String;
    fn summarize(&self) -> String {
        String::from("{Read more...}") // Isso vai ser mostrado por padrão caso a implementação não seja feita
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
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
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
}
