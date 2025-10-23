use std::io;

fn main() {
    let mut n = String::new();
    let _ = io::stdin().read_line(&mut n).ok();
    for _ in 0..n.trim().parse::<usize>().unwrap() {
        let mut b = String::new();
        let _ = io::stdin().read_line(&mut b).ok();
        let (bigger, smaller): (usize, usize) = {
            let v: Vec<usize> = b
                .split_whitespace()
                .map(|s| s.parse::<usize>().unwrap())
                .collect();
            if v[0] > v[1] {
                (v[0], v[1])
            } else {
                (v[1], v[0])
            }
        };
        let answer = combination(bigger, smaller);
        println!("{}", answer);
    }
}

fn combination(n: usize, r: usize) -> usize {
    let r = r.min(n - r);
    let mut numerator = 1;
    let mut denominator = 1;
    for i in 0..r {
        numerator *= n - i;
        denominator *= i + 1;
    }
    numerator / denominator
}
