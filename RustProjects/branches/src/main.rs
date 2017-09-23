fn main() {
    let number = 3;

    if number < 5 {
        println!("number is less than five!");
    } else if number == 5 {
        println!("number is equal to five!");
    } else {
        println!("number is greater than five");
    }
    
    let condition = true;
    let conditional = if condition {
        5
    } else {
        6
    };

    //Note: if you were to try the above if/else assignment block with mismatched
    //types the Rust compiler would complain

    println!("The value of conditional is: {}", conditional);
}
