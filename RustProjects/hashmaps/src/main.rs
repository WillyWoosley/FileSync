//HashMap is not part of the prelude, and therefore must be manually imported
use std::collections::HashMap;

fn main() {

    //creates new hashmap and adds two K/V value pairs
    //
    //note: all keys must be of the same type, ditto for values
    //note: hashmaps will take ownership of any heap allocated elements,
    //and copy any stack allocated ones
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    //will create an identical hashmap
    //note that zip() is used to construct a vec of tuples from teams and intial_scores
    //and collect() is used to map them as K/V pairs
    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let other_scores: HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();
    
    //values can be retrieved with .get(KEYNAME), which will yield an Option with the value
    //
    //note: must be passed a &_
    let score = scores.get(&String::from("Blue"));
    
    for (key, value) in &scores {
        println!("{}, {}", key, value);
    }

    //the following will insert and then overwrite the "Red" value
    scores.insert(String::from("Red"), 10);
    scores.insert(String::from("Red"), 25);

    //will check whether a value exists at the given key, inserting or_insert()'s argument
    //if no value is present
    scores.entry(String::from("Purple")).or_insert(100);
    scores.entry(String::from("Red")).or_insert(25);

    let text = "hello world wonderful world";
    let mut map = HashMap::new();

    //iterates through word, placing either a new entry into map under the word key
    //or updating the value if it does not exist
    //
    //note: * dereferences
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }
}
