#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
    Arkansas,
    //...etc
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn main() {
    println!("Coin value: {}", value_in_cents(Coin::Penny));
    println!("Coin value: {}", value_in_cents(Coin::Nickel));
    println!("Coin value: {}", value_in_cents(Coin::Dime));
    println!("Coin value: {}", value_in_cents(Coin::Quarter(UsState::Alaska)));

    let five = Some(5);
    let none: Option<i32> = None;

    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("One"),
        3 => println!("Three"),
        5 => println!("Five"),
        7 => println!("Seven"),
        _ => (),
    }

    let u8value = Some(3);
    
    match u8value {
        Some(3) => println!("Three"),
        _       => (),
    }

    if let Some(3) = u8value {
        println!("Also three");
    }
}

fn value_in_cents(coin: Coin) -> u32 {
    match coin {
        Coin::Penny          => {
            println!("Lucky penny!");
            1
        },
        Coin::Nickel         => 5,
        Coin::Dime           => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}", state);
            25
        },
    }
}

fn plus_one(num: Option<i32>) -> Option<i32> {
    match num {
        Some(i) => Some(i+1),
        None    => None,
    }
}
