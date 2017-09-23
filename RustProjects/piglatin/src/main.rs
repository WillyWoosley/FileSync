fn main() {
    let input = String::from("I am not speaking pig latin");

    //think on if theres a way to put this if/else into a single line
    for word in input.split_whitespace() {
        if word.len() > 1 {
            let v: Vec<char> = word.chars().collect();
            println!("{}", format!("{}-{}{}", &word[1..word.len()], &word[0..word.len()], "ay"));     
        } else {
            println!("{}", format!("{}{}", word, "ay"));
        }
    }
}
