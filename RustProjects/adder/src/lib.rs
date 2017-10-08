//cargo test --help: will provide options which go with cargo test 
//cargo test -- --help: will provide operations that go with the '--' seperator 
//
//tests run in parallel, so you must make sure that none of your tests both require access to the same data, 
//such as a single .txt or static global variable 
//this problem can be remedied by using the --test-threads flag, and seting it =1 
//
//--nocapture will cause the output of test functions to be output to the screen 
//(by default ouput of tests which pass are "captured" and are not printed to the terminal) 
//
//you can pass the name of a test to the 'cargo test' in order to run just the test of that name 
//i.e. 'cargo test FUNCTION_NAME 
//
//you can also pass just the first portion of a function name to 'cargo test', which will cause it
//to run all functions with the same prefix within their declaration
//i.e. 'cargo test FUNCTION_PREFIX'
//
//ignored functions will not be run, unless the --ignored flag is added to 'cargo test',
//in which case only the ignored functions will be run

#[cfg(test)]
mod tests {
    use super::*;
    
    #[test]
    fn exploration() {
    }

    #[test]
    fn another() {
        //panic!("Make this test fail");
    }

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            length: 8,
            width: 7,
        };
        let smaller = Rectangle {
            length: 5,
            width: 1,
        };

        assert!(larger.can_hold(&smaller));
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = Rectangle {
            length: 8,
            width: 7,
        };
        let smaller = Rectangle {
            length: 5,
            width: 1,
        };

        assert!(!smaller.can_hold(&larger));
    }

    #[test]
    fn it_adds_two() {
        assert_eq!(4, add_two(2));
    }

    //abysmal test, merely present to assert the presence of the assert_ne! macro
    #[test]
    fn it_passes_one() {
        assert_ne!(2, pass_one());
    }

    //the assert_eq! and assert_ne! macros must use values which implement the PartialEq
    //Debug traits

    #[test]
    fn greeting_contains_name() {
        let result = greeting("Carol");
        assert!{
            result.contains("Carol"),
            "Greeting did not contain name, value was '{}'", result
        };
    }

    //a should_panic test can either accept any panic as satisfying the test, or only
    //a specific panic as satisfying the test
    #[test]
    #[should_panic]
    fn greater_than_100() {
        Guess::new(200);
    }

    #[test]
    #[should_panic(expected = "Guess value must be between 1 and 100")]
    fn less_than_one() {
        Guess::new(0);
    }

    //example of an ignored function
    #[test]
    #[ignore]
    fn resource_intense() {
        //code goes here
    }
}

#[derive(Debug)]
pub struct Rectangle {
    length: u32,
    width: u32,
}

struct Guess {
    value: u32,
}

impl Rectangle {
    pub fn can_hold(&self, other: &Rectangle) -> bool {
        self.length > other.length && self.width > other.width
    }
}

impl Guess {
    pub fn new(value: u32) -> Guess {
        if value < 1 || value > 100 {
            panic!("Guess value must be between 1 and 100, got {}.", value);
        }

        Guess {
            value
        }
    }
}

pub fn add_two(a: i32) -> i32 {
    a+2
}

pub fn pass_one() -> i32 {
    1
}

pub fn greeting(name: &str) -> String {
    format!("Hello {}!", name)
}
