use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse().unwrap());
    let n = input.next().unwrap();
    let mut v = vec![];
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..n {
        if let Some(x) = input.next() {
            match x {
                1 => v.push(input.next().unwrap()),
                2 => writeln!(out, "{}", v.pop().unwrap_or(-1)).unwrap(),
                3 => writeln!(out, "{}", v.len()).unwrap(),
                4 => writeln!(out, "{}", if v.len() > 0 { 0 } else { 1 }).unwrap(),
                5 => writeln!(out, "{}", if v.len() > 0 { v[v.len() - 1] } else { -1 }).unwrap(),
                _ => writeln!(out, "0").unwrap(),
            }
        }
    }
}
