use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u32 = n.trim().parse().unwrap();
    if n == 1 {
        println!("1");
        return;
    }
    let mut i = 0;
    loop {
        if 2 << i > n - 1 {
            break;
        }
        i += 1;
    }
    println!("{}", 2 * (n - (1 << i)));
}
