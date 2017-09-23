
fn main() {
    let s = String::from("Hello world!");
    let slice = first_word(&s);

    let a = [1, 2, 3, 4, 5];
    let array_slice = &a[1..3];

    println!("{}", slice);
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    &s[..]
}
