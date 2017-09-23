fn main() {
    //creates new string capable of accepting new UTF-8 encoded data
    let mut s = String::new();
    
    //converts string literal (or and Display trait containing element)
    //into a String
    //
    //all s declaration lines result in the same String
    let data = "initial contents";
    let s = data.to_string();
    let s = "initial contents".to_string();
    let s = String::from("initial contents");

    //strings support standard concatenation operations
    let mut st = String::from("foo");
    st.push_str("bar");

    //concatenates st1 and st2, while leaving s2 as a valid string
    let mut st1 = String::from("foo");
    let st2 = String::from("bar");
    st1.push_str(&st2);

    //pushes single character
    st1.push('l');

    //st3 will equal concatted st1 and st2, with st2 still being referencable
    //and st1 no longer being valid
    let st3 = st1 + &st2;

    //when plain + concatenation gets unwieldy, the format! macro can be used
    //note that all passed string will still be valid after format!

    let tic= String::from("tic");
    let tac = String::from("tac");
    let toe = String::from("toe");
    let formatted = format!("{} {} {}", tic, tac, toe);

    //will seperate and print each character from the string literal
    for c in "hello world!".chars() {
        println!("{}", c);
    }

    //will seperate and print each characters bytes from the string literal
    for b in "hello world!".bytes() {
        println!("{}", b);
    }
}
