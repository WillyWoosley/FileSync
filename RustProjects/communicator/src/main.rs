extern crate communicator;
use communicator::client::connect;

fn main() {
    //both run the same function, the second is only possible
    //if the use statement is present
    communicator::client::connect();
    connect();
}
