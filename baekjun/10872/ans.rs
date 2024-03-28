use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u32 = n.trim().parse().unwrap();
    println!("{}", factorial(n));
}

fn factorial(n: u32) -> u32 {
    if n == 0 {
        return 1;
    }
    return n * factorial(n - 1);
}
