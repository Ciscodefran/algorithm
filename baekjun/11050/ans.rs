use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin())
        .expect("Error reading input");
    let mut iter = buf.split_whitespace();
    let n: u32 = iter.next().unwrap().parse().unwrap();
    let k: u32 = iter.next().unwrap().parse().unwrap();
    let mut cache = vec![vec![0; 11]; 11];
    for i in 0..=10 {
        cache[i][0] = 1;
        cache[i][i] = 1;
    }
    for i in 2..=10 {
        for j in 1..i {
            cache[i as usize][j as usize] = cache[i as usize - 1][j as usize - 1] + cache[i as usize - 1][j as usize];
        }
    }
    println!("{}", cache[n as usize][k as usize]);
}
