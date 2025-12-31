use std::io::{stdin, stdout, BufWriter, prelude::BufRead, prelude::Write};
use std::str;

/*
    Author: Koushik Sahu
    Created: 12:10:31 PM(12:10:31) IST(+05:30) 31-12-2025 Wed
*/
struct Solution {}

impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        let mut word_dict = word_dict;
        word_dict.sort();
        let mut dp = vec![false; s.len() + 1];
        dp[0] = true;
        for pos in 1..s.len() + 1 {
            for start in 1..=pos {
                let word = &s[start-1..pos];
                dp[pos] |= dp[start - 1] && Solution::exists(&word_dict, word); 
            }
        }
        dp[s.len()]
    }

    fn exists(word_dict: &Vec<String>, word: &str) -> bool {
        let (mut low, mut high) = (0, word_dict.len());
        while low < high {
            let mid = low + (high - low) / 2;
            if word_dict[mid].as_str() < word {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if low >= word_dict.len() {
            return false;
        }
        return word_dict[low] == word;
    }
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let s = "leetcode".to_string();
    let word_dict = vec!["leet".to_string(), "code".to_string()];
    writeln!(wr, "{}", Solution::word_break(s, word_dict)).unwrap();
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
