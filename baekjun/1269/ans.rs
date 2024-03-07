use std::io;
use std::collections::HashSet;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let [m, n] = [(); 2].map(|_| input.next().unwrap());
    let mut a = HashSet::new();
    let mut b = HashSet::new();
    for _ in 0..m {
        a.insert(input.next().unwrap());
    }
    for _ in 0..n {
        b.insert(input.next().unwrap());
    }
    println!("{}", a.symmetric_difference(&b).count());
}
