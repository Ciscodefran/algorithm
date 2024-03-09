use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<u64>().unwrap());
    let [a, b] = [(); 2].map(|_| input.next().unwrap());
    println!("{}", a * b / gcd(a, b));
}

fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
}
