use std::io;

fn main() {
    let mut buf = String::new();
    io::stdin().read_line(&mut buf).unwrap();
    let mut input = buf.split_whitespace().map(|x| x.parse().unwrap());
    let [n, k] = [(); 2].map(|_| input.next().unwrap());
    let mut v = (1..=n).collect::<Vec<usize>>();
    let mut idx = 0;
    let mut ans = Vec::new();
    while !v.is_empty() {
        idx = (idx + k - 1) % v.len();
        ans.push(v.remove(idx));
    }
    println!(
        "<{}>",
        ans.iter()
            .map(|x| x.to_string())
            .collect::<Vec<String>>()
            .join(", ")
    );
}
