use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin())
        .expect("Error reading input");
    let n: u32 = buf.trim().parse().unwrap();
    println!("{}", fibo(n));
}

fn fibo(n: u32) -> u32 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
