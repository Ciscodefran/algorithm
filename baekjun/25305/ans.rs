use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let [m, n] = [(); 2].map(|_| iter.next().unwrap());
    let mut v: Vec<u8> = iter.collect();
    v.sort();
    print!("{}", v[(m-n) as usize]);
}
