use std::fmt::Display;
use std::fmt::Debug;

pub trait Summarizable {
    //specifies a default value to be taken if no specific implementation is 
    //written for a Summarizable type
    //
    //could be specified without a default value as such:
    //fn summary(&self) -> String;
    fn summary(&self) -> String {
        //a default imolementation can call a method from a trait which has 
        //no default implementation
        format!("Read more from {}...", self.author_summary())
    }

    fn author_summary(&self) -> String;
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summarizable for NewsArticle {
    fn summary(&self) -> String {
        format!("{} by {} ({})", self.headline, self.author, self.location)
    }

    fn author_summary(&self) -> String {
        format!("{}", self.author)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summarizable for Tweet {
    fn summary(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }

    fn author_summary(&self) -> String {
        format!("@{}", self.username)
    }
}

//if one wanted to implement this same trait for something within a different crate
//import crate using "extern crate CRATENAME"
//namespace the trait using "use CRATENAME::TRAITNAME"
//
//note: either the trait being used or the type being used must be local in order
//to implement the trait

fn main() {
    let tweet = Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("of course, as you probably already know, people"),
        reply: false,
        retweet: false,
    };

    let article = NewsArticle {
        headline: String::from("Breaking news!"),
        location: String::from("Tanzania"),
        author: String::from("Tim Smith"),
        content: String::from("This is some of the most insane news I've ever heard"),
    };

    println!("1 new tweet: {}", tweet.summary());
    println!("New article!: {}", article.summary());
    notify(tweet);
}

//the following would implement a function which would require item to have two traits
//fn notify<T: Summarizable + Display>(item: T)

pub fn notify<T: Summarizable>(item: T) {
    println!("Breaking news! {}", item.summary());
}

//the following two functions are identical
fn some_function<T: Display + Clone, U: Clone + Debug>(t: T, u: U) -> i32 {
    //function body
    0
}

fn same_function<T, U>(t: T, u: U) -> i32
    where T: Display + Clone,
          U: Clone + Debug {
    //function body
    0
    }
