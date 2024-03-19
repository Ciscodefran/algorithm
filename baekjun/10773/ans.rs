use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<usize>().unwrap());
    let mut v = Vec::with_capacity(100000);
    for _ in 0..input.next().unwrap() {
        let n = input.next().unwrap();
        if n == 0 {
            v.pop();
        } else {
            v.push(n);
        }
    }
    println!("{}", v.iter().sum::<usize>());
}
