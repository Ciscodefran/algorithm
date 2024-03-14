use std::io::{self, BufWriter, Write};

fn main() {
    let mut v = vec![true; 123456 * 2 + 1];
    for i in 2..v.len() {
        if v[i] {
            for j in (i * 2..v.len()).step_by(i) {
                v[j] = false;
            }
        }
    }
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let mut out = BufWriter::new(io::stdout());
    loop {
        let n = input.next().unwrap();
        if n == 0 {
            break;
        }
        let mut cnt = 0;
        for i in n + 1..2 * n + 1 {
            if v[i as usize] {
                cnt += 1;
            }
        }
        writeln!(out, "{}", cnt).unwrap();
    }
}
