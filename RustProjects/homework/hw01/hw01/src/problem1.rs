//problem1.rs

//computes sum of elements in the input i32 slice
pub fn sum(slice: &[i32]) -> i32 {
    let mut sum: i32 = 0;

    for &i in slice {
        sum += i
    }

    sum
}

//deduplicates an input vector, retaining only the first occurrence of each distinct element
pub fn dedup(vs: &Vec<i32>) -> Vec<i32> {
    
    let mut vals: Vec<i32> = Vec::new();

    for &i in vs {
        match vals.contains(&i) {
            true => continue,
            false => vals.push(i)
        }
    }

    vals
}

//filters a vector based upon the result of a function taking an i32 and returning a bool
pub fn filter(vs: &Vec<i32>, pred: &Fn(i32) -> bool) -> Vec<i32> {
    
    let mut vals: Vec<i32> = Vec::new();
    
    for &i in vs {
        if pred(i) {
            vals.push(i);
        }
    }

    vals
}
