use std::io::{self, Write};

fn main() {
    let mut buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace();
    input.next();
    let mut v = input.map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
    v.sort();
    buf.clear();
    let mut writer = io::BufWriter::new(io::stdout());
    v.iter().for_each(|x| {
        writeln!(writer, "{}", x).unwrap();
    });
}
