enum IpAddrKind {
    V4,
    V6,
}

struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

enum Concise_IpAddr {
    V4(String),
    V6(String),
}

enum Format_IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

enum Message {
    Quit,
    Move {
        x: i32,
        y: i32,
    },
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        //call code
    }
}

fn main() {
    //increasingly well formatted enums and implementations
    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    route(four);
    route(six);

    let home = IpAddr {
        kind: IpAddrKind::V4,
        address: String::from("127.0.0.1"),
    };

    let loopback = IpAddr {
        kind: IpAddrKind::V6,
        address: String::from("::1"),
    };

    let concise_home = Concise_IpAddr::V4(String::from("127.0.0.1"));
    let concise_loopback = Concise_IpAddr::V6(String::from("::1"));

    let format_home = Format_IpAddr::V4(127, 0, 0, 1);
    let format_loopback = Format_IpAddr::V6(String::from("::1"));

    //advanced enum example and impl block example
    let m = Message::Write(String::from("hello"));
    m.call();

    //option examples
    let some_number = Some(5);
    let some_string = Some("a string");
    let absent_number: Option<i32> = None;

    let x = 5;
    let y = Some(6);
    //invalid!: 
    //let z = x+7;
}

fn route(ip_type: IpAddrKind) {
    //routing code
}
