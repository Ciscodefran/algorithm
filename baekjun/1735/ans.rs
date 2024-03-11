use std::io;
fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.trim().split_ascii_whitespace().map(|c| c.parse::<u32>().unwrap());
    let [a,b,c,d] = [(); 4].map(|_| input.next().unwrap());
    let mut n = a * d + c * b;
    let mut m = b * d;
    
    let mut c = gcd(m, n);
    while m%c == 0 && c != 1 {
        n /= c;
        m /= c;
        c = gcd(m, n);
    }
    println!("{n} {m}");
}

fn gcd(mut a: u32, mut b: u32) -> u32 {
    while b != 0 {
        let remainder = a % b;
        a = b;
        b = remainder;
    }
    a
}
