use std::io::{self, BufWriter, Write};

struct Node {
    number: u32,
    value: i32,
    front: *mut Node,
    back: *mut Node,
}

impl Node {
    fn new(number: u32, value: i32) -> Node {
        Node {
            number: number,
            value: value,
            front: std::ptr::null_mut(),
            back: std::ptr::null_mut(),
        }
    }
}

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut iter = buf.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = iter.next().unwrap();
    let head: *mut Node = &mut Node {
        number: 1,
        value: iter.next().unwrap(),
        front: std::ptr::null_mut(),
        back: std::ptr::null_mut(),
    };
    let mut prev: *mut Node = head;
    for i in 0..n {
        if i == 0 {
            unsafe {
                (*head).value = iter.next().unwrap();
                continue;
            }
        } else if i == n - 1 {
            unsafe {
                (*prev).back = head;
                (*head).front = prev;
                break;
            }
        }
        let node = Node::new((i + 1) as u32, iter.next().unwrap());
        unsafe {
            (*node).front = prev;
            (*prev).back = node;
        }
        prev = node;
    }

    let mut cur: *mut Node = head;
    let mut out = BufWriter::new(io::stdout());
    for _ in 0..n {
        unsafe {
            let value = (*cur).value;
            let number = (*cur).number;

            write!(out, "{} ", number).unwrap();
            writeln!(out, "{} ", value).unwrap();
            // write!(out, "{} ", number).unwrap();
            // pop_node(cur);
            // for _ in 0..value.abs() {
            //     if value > 0 {
            //         cur = (*cur).front;
            //     } else {
            cur = (*cur).back;
            //     }
            // }
        }
    }
}

fn pop_node(node: *mut Node) {
    unsafe {
        let front = (*node).front;
        let back = (*node).back;
        (*front).back = back;
        (*back).front = front;
    }
}
