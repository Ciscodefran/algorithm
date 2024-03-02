use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let [n, m] = [(); 2].map(|_| input.next().unwrap().parse().unwrap());
    let mut set = std::collections::HashSet::new();
    for _ in 0..n {
        set.insert(input.next().unwrap());
    }
    let mut cnt = 0;
    for _ in 0..m {
        if set.contains(input.next().unwrap()) {
            cnt += 1;
        }
    }
    println!("{}", cnt);
}
