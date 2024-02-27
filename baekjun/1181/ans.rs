use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.trim().split_whitespace().skip(1).collect::<Vec<&str>>();
    let mut out = BufWriter::new(io::stdout());
    input.sort_by(|a, b| {
        if a.len() == b.len() {
            a.cmp(b)
        } else {
            a.len().cmp(&b.len())
        }
    });
    // 중복 제거
    input.dedup();
    input.iter().for_each(|x| {
        writeln!(out, "{}", x).unwrap();
    });
}
