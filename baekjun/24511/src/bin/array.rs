use std::io::{self};

const MAX: usize = 200_000; // 📌
fn main() {
    // ♻️
    let buf = io::read_to_string(io::stdin()).unwrap();
    // 🔀
    let mut input = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let n = input.next().unwrap(); // 📌
    // 📦
    let mut qs: [u32; MAX] = [0; MAX];
    // ⏩️
    for i in 0..n {
        qs[i as usize] = input.next().unwrap();
    }
    // 🧺
    let mut container: [u32; MAX] = [0; MAX];
    // 👣
    let mut walker: usize = 1;
    for i in 0..n {
        // ♻️
        let tmp = input.next().unwrap();
        if qs[i as usize] == 0 {
            container[MAX - walker] = tmp;
            walker += 1;
        }
    }
    // ⏩️
    let step: u32 = input.next().unwrap();
    // 👣
    let mut front: usize = 0;
    for i in 0..step {
        container[i as usize] = input.next().unwrap();
        if walker != 1 {
            walker -= 1;
            print!("{} ", container[MAX - walker]);
        } else {
            print!("{} ", container[front]);
            front += 1;
        }
    }
}
