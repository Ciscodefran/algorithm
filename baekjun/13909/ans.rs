use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: f64 = buf.trim().parse().unwrap();
    println!("{}", n.sqrt() as u64);
}
