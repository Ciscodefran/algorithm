use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n = input.trim().parse::<u32>().unwrap();
    let mut v = vec![0; 10];
    while n > 0 {
        v[(n%10) as usize] += 1;
        n /= 10;
    }
    for i in (0..10).rev() {
        for _ in 0..v[i] {
            print!("{}", i);
        }
    }
}
