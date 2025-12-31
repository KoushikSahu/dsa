use std::io::{stdin, stdout, BufWriter, prelude::BufRead, prelude::Write};
use std::str;

/*
    Author: Koushik Sahu
    Created: 12:30:27 AM(00:30:27) IST(+05:30) 31-12-2025 Wed
*/

/*
* dp[i][j] = a[i] == a[j] && dp[i+1][j-1]
*/

struct Solution {}

/*
* You can iterate over centers and expand to the left and the right to get a O(1) memory solution
*/

impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let n = s.len();
        let s = s.chars().collect::<Vec<char>>();
        let mut dp = vec![vec![false; n]; n];
        dp[n-1][n-1] = true;
        dp[0][0] = true;
        let mut ans = 0;
        for i in (0..n-1).rev() {
            for j in 1..n {
                if i <= j {
                    dp[i][j] = s[i] == s[j] && if i + 1 <= j - 1 { dp[i+1][j-1] } else { true };
                }
            }
        }
        for i in 0..n {
            for j in 0..n {
                if dp[i][j] { ans += 1 }
            }
        }
        // dbg!(dp);
        ans
    }
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    writeln!(wr, "{}", Solution::count_substrings("abc".to_string())).unwrap();
    writeln!(wr, "{}", Solution::count_substrings("aaa".to_string())).unwrap();
    writeln!(wr, "{}", Solution::count_substrings("aaaaa".to_string())).unwrap();
}

#[macro_export]
macro_rules! dbg{
    ($($a:expr),*) => {
        #[cfg(debug_assertions)]
        eprintln!(
            concat!("{}:{}:{}: ",$(stringify!($a), " = {:?}, "),*),
            file!(), line!(), column!(), $($a),*
            );
        #[cfg(not(debug_assertions))]
        {};
    }
}

struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: str::SplitWhitespace<'static>,
}

#[allow(dead_code)]
impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: vec![],
            buf_iter: "".split_whitespace(),
        }
    }
    fn next<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_whitespace())
            }
        }
    }
    fn try_next(&mut self) -> Option<String> {
        loop {
            self.buf_str.clear();
            let bytes_read = self
                .reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            if bytes_read == 0 {
                return None; // End of file reached
            }
            return unsafe { Some(str::from_utf8_unchecked(&self.buf_str).trim().to_owned()) };
        }
    }
}

fn main() {
    let (stdin, stdout) = (stdin(), stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());
    #[allow(unused_variables)]
    let t: i32 = 1;
    //let t: i32 = scan.next(); 
    for _ in 0..t {
        solve(&mut scan, &mut out);
    }
}
