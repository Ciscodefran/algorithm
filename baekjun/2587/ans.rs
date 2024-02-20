use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut v = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap()).collect::<Vec<_>>();
    v.sort();
    let avg = v.iter().sum::<u32>()/v.len() as u32;
    let mid = v[v.len()/2];
    print!("{avg}\n{mid}");
}
