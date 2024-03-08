use std::io;
use std::collections::HashSet;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let chs = buf.trim().chars().collect::<Vec<char>>();
    let mut s = HashSet::new();
    let mut len = 1;
    while len <= chs.len() {
        for i in 0..(chs.len() - len + 1) {
            s.insert(chs[i..i+len].iter().collect::<String>());
        }
        len += 1;
    }
    println!("{}", s.len());
}

