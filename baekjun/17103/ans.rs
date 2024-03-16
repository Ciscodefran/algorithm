use std::io::{self, BufWriter, Write};

fn main() {
    let primes = {
        let mut is_prime = vec![true; 1_000_001];
        is_prime[0] = false;
        is_prime[1] = false;
        for i in 2..1_001 {
            if is_prime[i] {
                for j in (i * i..1_000_001).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }
        is_prime
    };
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf
        .trim()
        .split_whitespace()
        .skip(1)
        .map(|x| x.parse::<usize>().unwrap());
    let mut out = BufWriter::new(io::stdout());
    for k in input {
        let mut count = 0;
        for i in 2..k / 2 + 1 {
            if primes[i] && primes[k - i] {
                count += 1;
            }
        }
        writeln!(out, "{}", count).unwrap();
    }
}
