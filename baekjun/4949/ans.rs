use std::io;

fn main() {
    let mut buf = String::new();
    loop {
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        if buf.trim().is_empty() {
            break;
        }
        if buf.trim_end() == "." {
            break;
        }
        if buf.ends_with('\n') || buf.ends_with('\r') {
            buf.pop();
        }
        let src = &mut buf.trim();
        let v = src
            .chars()
            .filter(|&c| c == '(' || c == ')' || c == '[' || c == ']')
            .collect::<Vec<char>>();
        let mut stack = Vec::new();
        for c in v {
            match c {
                '(' | '[' => stack.push(c),
                ')' => {
                    if stack.pop() != Some('(') {
                        *src = "no";
                        break;
                    }
                }
                ']' => {
                    if stack.pop() != Some('[') {
                        *src = "no";
                        break;
                    }
                }
                _ => {}
            }
        }
        if !stack.is_empty() {
            *src = "no";
        } else if *src != "no" {
            *src = "yes";
        }
        println!("{}", src);
    }
}
