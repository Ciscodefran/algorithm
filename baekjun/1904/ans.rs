use std::io::stdin;

const MOD: usize = 15746;

fn main() {
    let n: usize = {
        let mut s = String::new();
        stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mut dp = vec![0; n+2];
    dp[1] = 1;
    dp[2] = 2;
    for i in 3..=n {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    println!("{}", dp[n]);
}
