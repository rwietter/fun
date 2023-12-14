mod adventofcode;
mod leetcode;
mod lists;

use adventofcode::callibration;
use leetcode::easy::*;
use leetcode::medium::*;
use lists::list;

fn main() {
    list::list();
    two_sum::two_sum();
    ice_cream::ice_cream();
    callibration::callibration();
}
