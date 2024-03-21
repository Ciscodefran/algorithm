use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let n: usize = buf.trim().parse().unwrap();
    'a: for _ in 0..n {
        buf.clear();
        io::stdin().read_line(&mut buf).unwrap();
        let mut input = buf.trim().chars();
        let mut cnt = 0;
        for ch in input {
            match ch {
                '(' => cnt += 1,
                ')' => {
                    cnt -= 1;
                }
                _ => (),
            }
            if cnt < 0 {
                println!("NO");
                continue 'a;
            }
        }
        if cnt == 0 {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}
