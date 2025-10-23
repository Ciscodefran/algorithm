use std::io::stdin;
fn dp(n: usize, m: &mut Vec<usize>) -> usize {
    m[1] = 1;
    m[2] = 1;
    m[3] = 1;
    for i in 4..=n {
        if m[i] == 0 {
            m[i] = m[i-2] + m[i-3];
        }
    }
    m[n]
}
fn main() {
    let n: usize = {
        let mut buf: String = String::new();
        stdin().read_line(&mut buf).unwrap();
        buf.trim().parse::<usize>().unwrap()
    };
    let mut m: Vec<usize> = vec!(0; 101);
    for _ in 0..n {
        let i: usize = {
            let mut buf: String = String::new();
            stdin().read_line(&mut buf).unwrap();
            let j = buf.trim().parse::<usize>().unwrap();
            dp(j, &mut m)
        };
        println!("{}", i);
    }
}
