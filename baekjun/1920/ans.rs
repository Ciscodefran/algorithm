use std::io::{self, BufWriter, Write};
fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut out = BufWriter::new(io::stdout());
    let mut input = buf
        .split_ascii_whitespace()
        .map(|x| x.parse::<usize>().unwrap());
    let n = input.next().unwrap();
    let mut a = Vec::new();
    for _ in 0..n {
        a.push(input.next().unwrap());
    }
    a.sort();
    let m = input.next().unwrap();
    for _ in 0..m {
        let o = a.binary_search(&input.next().unwrap()).is_ok();
        writeln!(out, "{}", if o { 1 } else { 0 }).unwrap();
    }
}
