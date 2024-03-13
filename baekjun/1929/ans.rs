use std::io::{self, BufWriter, Write};

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let mut input = buf.trim().split_whitespace();
    let [m, n] = [(); 2].map(|_| input.next().unwrap().parse::<usize>().unwrap());
    let mut prime = vec![true; 1000001];
    prime[0] = false;
    prime[1] = false;
    for i in 2..1000001 {
        if prime[i] {
            let mut j = 2;
            while i * j < n + 1 {
                prime[i * j] = false;
                j += 1;
            }
        }
    }
    let mut out = BufWriter::new(io::stdout());
    for i in m..n + 1 {
        if prime[i as usize] {
            writeln!(out, "{}", i).unwrap();
        }
    }
}
