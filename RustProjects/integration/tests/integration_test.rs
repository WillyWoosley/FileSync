//such integration tests are only possible in crates which contain a lib.rs
//this is because only library crates expose functions which are to be used
//outside of the context of this their crate
extern crate integration;

mod common;

#[test]
fn it_adds_two() {
    common::setup();
    assert_eq!(4, integration::add_two(2));
}
