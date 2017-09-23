use std::collections::HashMap;

fn main() {
    let v = vec![0];
    println!("Mean: {}", mean(&v));
    println!("Median: {}", median(&v));
    println!("Mode: {}", mode(&v));
}

//functions expect non-null vecs, will panic otherwise
fn mean(v: &Vec<i32>) -> f32 {
    let mut sum = 0;
    let elements = v.len() as i32;

    for x in v {
        sum += *x;
    }

    sum as f32/elements as f32
}

fn median(v: &Vec<i32>) -> i32 {
    let mut instance = v.clone(); 
    instance.sort();
    
    instance[instance.len()/2]
}

fn mode(v: &Vec<i32>) -> i32 {
    let mut map = HashMap::new();
    let mut mode = (0, 0);

    for x in v {
        let count = map.entry(*x).or_insert(0);
        *count += 1;
    }

    for (number, occur) in map {
        if occur > mode.1 {
            mode = (number, occur);
        }
    }

    mode.0
}
