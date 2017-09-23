#[derive(Debug)]
struct Rectangle {
    length: u32,
    width: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.length * self.width
    }

    fn can_hold(&self, subject: &Rectangle) -> bool {
        self.length > subject.length && self.width > subject.width
    }

    fn square(side: u32) -> Rectangle {
        Rectangle {
            length: side,
            width: side,
        }
    }
}

fn main() {
    let rect1 = Rectangle {
            length: 50,
            width: 30,
        };


    println!("The area of the rectangle is {} square pixels",
             rect1.area());

    println!("rect1 is: {:?}", rect1);
    println!("another view of rect1's state is: {:#?}", rect1);

    let rect2 = Rectangle {
            length: 40,
            width: 10,
        };

    let rect3 = Rectangle {
            length: 45,
            width: 60,
        };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    let square = Rectangle::square(10);

    println!("the area of square is: {}", square.area());
}
