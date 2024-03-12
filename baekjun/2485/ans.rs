use std::io;
use std::collections::HashSet;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let input = buf.split_whitespace().skip(1).map(|s| s.parse::<u64>().unwrap()).collect::<Vec<_>>();
    let mut set = HashSet::new();
    for i in 1..input.len() {
        set.insert(input[i] - input[i - 1]);
    }
    let mut ans = 0;
    for i in set {
        ans = gcd(ans, i);
    }
    let res = (input[input.len() - 1] - input[0]) / ans - input.len() as u64 + 1;
    println!("{}", res);
}

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
