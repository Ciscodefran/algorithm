use std::{collections::VecDeque, io};

const MAX: usize = 100_000;
fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let mut qs: [u32; MAX] = [0; MAX];
    let n: u32 = input.next().unwrap();
    let mut cnt: usize = 0;
    for i in 0..n {
        let v = input.next().unwrap();
        if v == 0 {
            cnt += 1;
        }
        qs[i as usize] = v;
    }
    let mut container = VecDeque::<u32>::with_capacity(cnt);
    for i in 0..n {
        let tmp = input.next().unwrap();
        if qs[i as usize] == 0 {
            container.push_front(tmp);
        }
    }
    let step = input.next().unwrap();
    for _ in 0..step {
        let tmp = input.next().unwrap();
        container.push_back(tmp);
        print!("{} ", container.pop_front().unwrap());
    }
}
