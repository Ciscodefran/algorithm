use std::collections::VecDeque;
use std::io::{self, BufWriter, Write};

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace();
    let n: usize = iter.next().unwrap().parse().unwrap();
    let mut out = BufWriter::new(io::stdout());
    let mut stack = VecDeque::new();
    for _ in 0..=n {
        if let Some(cmd) = iter.next() {
            match cmd {
                "push" => {
                    let x: i32 = iter.next().unwrap().parse().unwrap();
                    stack.push_back(x);
                }
                "pop" => {
                    writeln!(out, "{}", stack.pop_front().unwrap_or(-1)).unwrap();
                }
                "size" => {
                    writeln!(out, "{}", stack.len()).unwrap();
                }
                "empty" => {
                    writeln!(out, "{}", if stack.is_empty() { 1 } else { 0 }).unwrap();
                }
                "front" => {
                    writeln!(out, "{}", stack.get(0).unwrap_or(&-1)).unwrap();
                }
                "back" => {
                    writeln!(out, "{}", stack.get(stack.len() - 1).unwrap_or(&-1)).unwrap();
                }
                _ => {}
            }
        }
    }
}
