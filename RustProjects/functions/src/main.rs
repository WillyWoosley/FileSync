fn main() {
    println!("Hello world!");

    let x = 5;

    another_function();
    para_fn(x);
    println!("The value of return_func() is: {}", return_func());
    println!("The value of x + 1 is: {}", plus_one(x));
}

fn another_function() {
    println!("Another function.");
}

fn para_fn(x: i32) {
    println!("The value of x is: {}", x);
}

fn return_func() -> i32 {
    5+1
}

fn plus_one(x: i32) -> i32 {
    x+1
}
