use std::io::{self, BufWriter, Write};
use std::collections::LinkedList;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = iter.next().unwrap();
    let mut balloons = LinkedList::new();
    for (idx, num) in iter.enumerate() {
        balloons.push_back((idx + 1, num));
    }
    let mut i = 0;
    loop {
        let mut a = balloons.remove(i);
    }
}
