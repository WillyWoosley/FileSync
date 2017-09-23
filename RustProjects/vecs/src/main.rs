enum SpreadsheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {
    //basic vec initialization
    //note that the mut must be added if any values are to be mapped to v
    let mut v: Vec<i32> = Vec::new();

    //pre-populated vec created using vec! macro
    let ve = vec![1, 2, 3];

    //add elements to a vector
    v.push(4);
    v.push(5);
    v.push(6);

    //read elements from a vector
    //first will panic if no element is present at its index
    //wheras second will just contain the None option
    let first: &i32 = &v[0];
    let second: Option<&i32> = v.get(2);

    //the following line would create an error, as .push() requires
    //a mutable reference to the vec, thereby violating Rust's borrowing rules
    //v.push(7)
    
    //this is how you get around vecs only being able to contain a single type,
    //since all vec elements are SpreadsheetCell
    
    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ];
}
