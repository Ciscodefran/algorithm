use std::io::{self, BufWriter, Write};

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: u64 = buf.trim().parse().unwrap();
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..n {
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        let m: u64 = buf.trim().parse().unwrap();
        if m == 0 || m == 1 {
            writeln!(out, "2").unwrap();
            continue;
        }
        let mut i = m;
        loop {
            if is_prime(i) {
                writeln!(out, "{}", i).unwrap();
                break;
            }
            i += 1;
        }
    }
}

fn is_prime(n: u64) -> bool {
    if n == 1 {
        return false;
    }
    for i in 2..(n as f64).sqrt() as u64 + 1 {
        if n % i == 0 {
            return false;
        }
    }
    true
}
