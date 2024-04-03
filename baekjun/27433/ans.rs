use std::io;

fn main() {
    let mut input = string::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: u32 = input.trim().parse().unwrap();
    println!("{}", factorial(n));
}

fn factorial(n: u32) -> u32 {
    if n == 0 {
        return 1;
    }
    n * factorial(n - 1)
}
