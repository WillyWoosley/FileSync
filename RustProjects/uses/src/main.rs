enum TrafficLight {
    Green,
    Yellow,
    Red,
}

enum Ratings {
    Good,
    Alright,
    Bad,
}

use TrafficLight::{Green, Yellow};
use Ratings::*;

fn main() {
    let green = Green;
    let yellow = Yellow;
    let red = TrafficLight::Red;

    let good = Good;
    let alright = Alright;
    let bad = Bad;
}
