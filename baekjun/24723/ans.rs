use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n = buf.trim().parse::<u32>().unwrap();
    println!("{}", (2 as u32).pow(n));
}
