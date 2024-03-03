use std::io::{self, BufWriter, Write};
use std::collections::HashMap;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let n: usize = input.next().unwrap().parse().unwrap();
    let mut log = HashMap::new();
    for _ in 0..n {
        let [name, state] = [(); 2].map(|_| input.next().unwrap());
        if state == "enter" {
            log.insert(name.to_string(), ());
        } else {
            log.remove(name);
        }
    }
    let mut log: Vec<_> = log.keys().collect();
    log.sort();
    let out = io::stdout();
    let mut out = BufWriter::new(out.lock());
    for name in log.iter().rev() {
        writeln!(out, "{}", name).unwrap();
    }
}
