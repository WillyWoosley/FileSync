fn main() {
   
    //ownership rules do not apply to string literals, as they are stored on the stack
    //and are therefore treated the same as any other stack variable
    let literal = "hello world";
    let new_owner = literal;

    println!("literal: {}, new_owner: {}", literal, new_owner);
    
    let x = 5;
    println!("x: {}", add_one(x)+1);
}

fn add_one(x: i32) -> i32 {
    x+1
}
