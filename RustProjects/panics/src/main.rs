use std::io;
use std::io::Read;
use std::fs::File;
use std::io::ErrorKind;

fn main() {
    //panic!("crash and burn");
    //
    //most basic, user triggered panic!
    
    //panic! is in a file in the standard library
    //the whole backtrace can be seen by prepending
    //"RUST_BACKTRACE=1" to your "cargo run" command
    //
    //let v = vec![1, 2, 3];
    //v[100];
   
    //you can find if a function will return a result by either
    //looking it up in the documentation or by intentionally
    //misannoting the value
    let f = File::open("hello.txt");
    
    let f = match f {
        Ok(file) => file,
        Err(ref error) if error.kind() == ErrorKind::NotFound => {
            match File::create("hello.txt") {
                Ok(fi) => fi,
                Err(er) => panic!("Tried to create file, but encountered an error: {:?}", er),
            }
        },
        Err(error) => panic!("There was a problem opening the file: {:?}", error),
    };

    //will call panic! if test.txt does not exist
    //let file = File::open("test.txt").unwrap();
    
    //will call panic! with custom error mesage if file does not exist
    //let otherfile = File::open("othertest.txt").expect("Failed to open othertest.txt");
}

//propogating errors
//this can be useful in order to deliver more information back to the calling
//function about what exactly when wrong, so that you can decide by instance
//what it is you want to do
fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

//contains condensed error propogation using ?
//
//the ? takes the form of the match block in the initial function:
//if Ok is returned then that value will be taken
//if an Err is returned then that Err will be returned from the function
//
//? can only be used with functions which return a Result type
fn condensed_read_username() -> Result<String, io::Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

//condenses the previous function down even further
fn really_compact_read_username() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s) 
}
