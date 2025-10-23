use std::io::{stdin, Read};
use std::cmp::max;

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<isize>().unwrap());
    let n = input.next().unwrap();
    let v: Vec<isize> = {
        input.collect()
    };
    let mut current = v[0];
    let mut max_sum = v[0];
    for i in 1..n as usize {
        current = max(v[i], current + v[i]);
        max_sum = max(max_sum, current);
    }
    println!("{}", &max_sum);
}
