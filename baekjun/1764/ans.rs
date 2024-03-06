use std::io::{self, BufWriter, Write};
use std::collections::HashSet;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.trim().split_ascii_whitespace();
    let [n, m] = [(); 2].map(|_| input.next().unwrap().parse().unwrap());
    let mut out = BufWriter::new(io::stdout());
    let mut set1 = HashSet::new();
    let mut set2 = HashSet::new();
    for _ in 0..n {
        set1.insert(input.next().unwrap());
    }
    for _ in 0..m {
        set2.insert(input.next().unwrap());
    }
    let mut ans = set1.intersection(&set2).collect::<Vec<_>>();
    ans.sort();
    writeln!(out, "{}", ans.len()).unwrap();
    for x in ans.iter() {
        writeln!(out, "{}", x).unwrap();
    }
}

