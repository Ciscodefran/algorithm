use std::io::{self, BufWriter, Write};
use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace().map(|s| s.parse::<isize>().unwrap());
    let m = input.next().unwrap();
    for _ in 0..m {
        let i = input.next().unwrap();
        if let Some(x) = map.get_mut(&i) {
            *x += 1;
        } else {
            map.insert(i, 1);
        }
    }
    let n = input.next().unwrap();
    let mut out = BufWriter::new(io::stdout());
    for i in 0..n {
        write!(out, "{} ", map.get(&input.next().unwrap()).unwrap_or(&0)).unwrap();
    }
}   
