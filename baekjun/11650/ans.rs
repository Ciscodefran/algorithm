use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut v = vec![];
    for [x,y] in (0..n).map(|_| [(); 2].map(|_| input.next().unwrap().parse::<i32>().unwrap())) {
        v.push([x,y]);
    }
    v.sort_by(|a, b| {
        if a[0] == b[0] {
            a[1].cmp(&b[1])
        } else {
            a[0].cmp(&b[0])
        }
    });
    let mut out = BufWriter::new(io::stdout());
    v.iter().for_each(|x| writeln!(out, "{} {}", x[0], x[1]).unwrap());
}


