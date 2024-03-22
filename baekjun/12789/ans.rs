use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().map(|x| x.parse::<u32>().unwrap());
    let n = iter.next().unwrap();
    let mut stack: Vec<u32> = Vec::with_capacity(n as usize);
    let mut cnt = 1;
    for _ in 1..=n {
        let x = iter.next().unwrap();
        if x == cnt {
            cnt += 1;
        } else {
            stack.push(x);
        }
        while let Some(&x) = stack.last() {
            if x == cnt {
                stack.pop();
                cnt += 1;
            } else {
                break;
            }
        }
    }
    if stack.is_empty() {
        println!("Nice");
    } else {
        println!("Sad");
    }
}
