use std::io::{stdin, stdout, BufWriter, prelude::BufRead, prelude::Write};
use std::str;

/*
    Author: Koushik Sahu
    Created: 10:33:06 PM(22:33:06) IST(+05:30) 29-12-2025 Mon
*/

struct Solution {}

impl Solution {
    pub fn partition(s: String) -> Vec<Vec<String>> {
        let s = s.chars().collect::<Vec<char>>();
        let n = s.len() as i32;
        let mut ans = vec![];
        for i in 0..(1<<(n - 1)) {
            let mut all_palindromes = true;
            let mut a = vec![];
            let mut tmp = vec![];
            for j in 0..n {
                if j > 0 && ((i >> j) & 1) != ((i >> (j - 1)) & 1) {
                    if Solution::is_palindrome(&a) {
                        tmp.push(a.iter().collect::<String>());
                    } else {
                        all_palindromes = false;
                        break;
                    }
                    a.clear();
                }
                a.push(s[j as usize]);
            }
            if a.len() > 0 && Solution::is_palindrome(&a) {
                tmp.push(a.iter().collect());
            } else {
                all_palindromes = false;
            }
            if all_palindromes {
                ans.push(tmp);
            }
        }
        return ans;
    }

    pub fn is_palindrome(s: &Vec<char>) -> bool {
        let mut l = 0;
        let mut h = s.len() - 1;
        while l < h {
            if s[l] != s[h] {
                return false;
            }
            l += 1;
            h -= 1;
        }
        return true;
    }
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    dbg!(Solution::partition("aab".to_string()));
    dbg!(Solution::partition("a".to_string()));
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
