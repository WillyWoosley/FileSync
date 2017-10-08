struct Point<T> {
    x: T,
    y: T,
}

struct Diverse_Point<T, U> {
    x: T,
    y: U,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

impl<T, U> Diverse_Point<T, U> {
    fn mixup<V, W>(self, other: Diverse_Point<V, W>) -> Diverse_Point<T, W> {
        Diverse_Point {
            x: self.x,
            y: other.y,
        }
    }
}

//Option and Result are examples of two enums in std which implement generics
//
//struct Option<T> {
//  Some(T),
//  None
//}
//
//struct Result<T, E> {
//  Ok(T),
//  Err(E),
//}

fn main() {
    let integer = Point {
        x: 1,
        y: 10,
    };

    let float = Point {
        x: 1.0,
        y: 4.0,
    };

    //won't work
    //in the definition of point, while T is generic
    //x and y are both guaranteed to be of the same generic type
    //
    //let mixed = Point {
    //  x: 9,
    //  y: 7.0,
    //}

    //this will work because x and y are said to be of two different
    //generic types, although this does not necessitate them being
    //of different types
    let will_work = Diverse_Point{
        x: 2,
        y: 12.0,
    };
    
    let also_works = Diverse_Point {
        x: 9.5,
        y: 3,
    };

    let numbers = vec![34, 50, 25, 100, 65];
    let result = largest(&numbers);
    println!("The largest number is {}", result);

    let chars = vec!['y', 'm', 'a', 'q'];
    let result = largest(&chars);
    println!("The largest char is {}", result);
}

fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for num in list {
        if (num > largest) {
            largest = num;
        }
    }

    largest
}

fn old_largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list.iter() {
        if item > largest {
            largest = item;
        }
    }

    largest
}
