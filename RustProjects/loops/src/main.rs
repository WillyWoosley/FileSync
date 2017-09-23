fn main() {
    let mut x = 5;

    loop {
        println!("I'll never stop without a break statement");
        x-=1;

        if x==0 {
            break;
        }
    
    }
    
    let mut y = 3;

    while y != 0 {
        println!("The value of y is: {}", y);
        y-=1;
    }

    let ar = [1, 2, 3, 4, 5];

    for element in ar.iter() {
        println!("the value is: {}", element);
    }
    
    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("Blastoff!");
}
