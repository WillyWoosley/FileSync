use std::fmt::Display;

//structs can hold references, but they must all have lifetime annotations
struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }

    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

fn main() {
    let string1 = String::from("abcd");
    let result;
    {
    let string2 = "xyz";

    result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);
    }

    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.')
        .next()
        .expect("Could not find a '.'");
    let i = ImportantExcerpt {
        part: first_sentence,
    };
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str { 
    
    if x.len() > y.len() {
        x 
    } else {
        y
    }
}

//no need to add a lifetime to the second parameter, since the first element
//is always the one which will be returned
fn return_first<'a>(x: &'a str, y: &str) -> &'a str {
    x
}

//example of a function incorperating generics, traits, and lifetimes
fn longest_with_an_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str
    where T: Display 
{
    println!("Announcement! {}", ann);
    if x.len() > y.len() {
        x
    } else {
        y
    }

}

//functions which return references return a reference to one of the parameters
//as all of the variables called within the scope of the function will be
//garbage collected once the function call is over, leaving dangling references

//the Rust elision rules adhere to the following pattern:
//1. each refernce parameter is assigned its own distinct lifetime parameter
//2. if there is exactly one input parameter, the lifetime of this parameter
//  is assigned to all output parameters
//3. if there are mulltiple inputs, but one is a self-reference, then the lifetime
//  of self is assigned to all ouput parameters

//the 'static lifetime parameter can be used to create a variable which has a lifetime
//spanning the duration of the program
//
//before using this lifetime annotation, ensure that you really do want whatever value
//you are annotating to last the entirety of the program
