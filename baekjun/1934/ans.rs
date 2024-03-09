use std::io::{self, Write, BufWriter};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.trim().split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..input.next().unwrap() {
        let [a, b] = [(); 2].map(|_| input.next().unwrap());
        let max = a.max(b);
        let mut cnt = 1;
        while max*cnt % a != 0 || max*cnt % b != 0 {
            cnt += 1;
        }
        writeln!(out, "{}", max*cnt).unwrap();
    }
}
