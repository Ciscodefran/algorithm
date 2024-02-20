use std::io;

fn main() {
    let buf = io::read_to_string(io::stdin()).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let [n, m] = [(); 2].map(|_| input.next().unwrap().parse::<u8>().unwrap());
    let v: Vec<_> = input.map(|s| s.chars().collect::<Vec<_>>()).collect();
    let mut min = 64;
    for i in 0..=n-8 {
        for j in 0..=m-8 {
            let mut board = String::new();
            for y in 0..8 {
                for x in 0..8 {
                    board.push(v[(i+y) as usize][(j+x) as usize]);
                }
            }
            let cmp = get_need_change(&board);
            if cmp < min {
                min = cmp;
            }
        }
    }
    print!("{min}")
}
fn get_need_change(buf: &str) -> u8 {
    let mut board = buf.chars();
    let mut start_with_b = 0;
    let mut start_with_w = 0;
    for i in 0..8 {
        for j in 0..8 {
            let char = board.next().unwrap();
            if i%2 == 0 {
                if char == 'W' {
                    if j%2 == 0 {
                        start_with_b += 1;
                    } else {
                        start_with_w += 1;
                    }
                } else { // B
                    if j%2 == 0 {
                        start_with_w += 1;
                    } else {
                        start_with_b += 1;
                    }
                }
            } else {
                if char == 'B' {
                    if j%2 == 0 {
                        start_with_b += 1;
                    } else {
                        start_with_w += 1;
                    }
                } else { // B
                    if j%2 == 0 {
                        start_with_w += 1;
                    } else {
                        start_with_b += 1;
                    }
                }
            }
        }
    }
    start_with_w.min(start_with_b)
}
