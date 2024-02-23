use std::io::{self, BufWriter, Write};

fn main() {
    const MAX_NUM: u16 = 10000;
    let mut count = [0; MAX_NUM as usize + 1];
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: usize = buf.trim().parse().unwrap();
    for _ in 0..n {
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        let i: &u16 = &buf.trim().parse().unwrap();
        count[*i as usize] += 1;
    }
    let mut out = BufWriter::with_capacity(131072, io::stdout());
    for i in 1..=10000 {
        for _ in 0..count[i] {
            writeln!(out, "{i}").unwrap();
        }
    }
}
