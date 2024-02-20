use std::io;

fn main() {
    let s = io::read_to_string(io::stdin()).unwrap();
    let mut v = s.trim().split_whitespace()
        .map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();

    for i in 1..v.len() {
        for j in i+1..v.len() {
            if v[i] > v[j] {
                v.swap(i, j);
            }
        }
    }

    for i in 1..v.len() {
        println!("{}", v[i]);
    }
}
