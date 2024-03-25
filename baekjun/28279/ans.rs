use std::collections::VecDeque;
use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf
        .split_ascii_whitespace()
        .map(|x| x.parse::<i32>().unwrap());
    let mut v: VecDeque<i32> = VecDeque::new();
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..input.next().unwrap() {
        if let cmd = input.next().unwrap() {
            match cmd {
                1 => v.push_front(input.next().unwrap()),
                2 => v.push_back(input.next().unwrap()),
                3 => writeln!(out, "{}", v.pop_front().unwrap_or(-1)).unwrap(),
                4 => writeln!(out, "{}", v.pop_back().unwrap_or(-1)).unwrap(),
                5 => writeln!(out, "{}", v.len()).unwrap(),
                6 => writeln!(out, "{}", if v.is_empty() { 1 } else { 0 }).unwrap(),
                7 => writeln!(out, "{}", v.front().unwrap_or(&-1)).unwrap(),
                8 => writeln!(out, "{}", v.back().unwrap_or(&-1)).unwrap(),
                _ => (),
            }
        }
    }
}
