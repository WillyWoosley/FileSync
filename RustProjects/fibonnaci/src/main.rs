use std::io;

fn main() {
    
    loop {
        println!("Please specify the index at which you would like to check");

        let mut input = String::new();

        io::stdin().read_line(&mut input)
            .expect("Failed to read line");

        let input: i32= match input.trim().parse() {
            Ok(num) => num,
            Err(_)  => {
                println!("Please input a valid number");
                continue
            },
        };

        if input < 1 {
            println!("Please input a positive index");
            continue;
        }

        println!("{}", fibonnaci(input));
    }
}

fn fibonnaci(val: i32) -> i32 {
    if val==1 {
        0
    } else if val==2 {
        1
    } else {
        fibonnaci(val-1) + fibonnaci(val-2)
    }
}
