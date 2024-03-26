use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: u32 = buf.trim().parse().unwrap();
    println!("{}", n * (n - 1));
}
