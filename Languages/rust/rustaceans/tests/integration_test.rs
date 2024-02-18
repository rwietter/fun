use hubgt;

mod common;

#[test]
fn it_adds_two() {
    common::setup();
    assert_eq!(4, hubgt::add_two(2));
}
