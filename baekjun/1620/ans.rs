use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let [m, n] = [(); 2].map(|_| input.next().unwrap().parse().unwrap());
    let mut map = std::collections::HashMap::new();
    let mut map2 = std::collections::HashMap::new();
    for i in 1..=m {
        let name = input.next().unwrap();
        map.insert(name, i);
        map2.insert(i, name);
    }
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..n {
        let name = input.next().unwrap();
        if let Ok(num) = name.parse::<usize>() {
            writeln!(out, "{}", map2.get(&num).unwrap()).unwrap();
        } else {
            writeln!(out, "{}", map.get(name).unwrap()).unwrap();
        }
    }
}
