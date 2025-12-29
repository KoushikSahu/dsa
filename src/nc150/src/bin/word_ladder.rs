use std::collections::VecDeque;
use std::io::{stdin, stdout, BufWriter, prelude::BufRead, prelude::Write};
use std::str;

/*
    Author: Koushik Sahu
    Created: 10:58:03 PM(22:58:03) IST(+05:30) 28-12-2025 Sun
*/

struct Solution {}

struct Words {
    id: i32,
    depth: i32
}

impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        let n = word_list.len();
        let mut idx = n;
        for i in 0..n {
            if word_list[i] == end_word {
                idx = i;
                break;
            }
        }
        if idx == n {
            return 0;
        }
        let mut g: Vec<Vec<i32>> = vec![vec![]; n + 1];
        for i in 0..n {
            if Solution::worddiff_cnt(&begin_word, &word_list[i]) == 1 {
                g[0].push(i as i32 + 1);
                g[i + 1].push(0);
            }
        }
        for i in 0..n {
            for j in i..n {
                if Solution::worddiff_cnt(&word_list[i], &word_list[j]) == 1 {
                    g[i + 1].push(j as i32 + 1);
                    g[j + 1].push(i as i32 + 1);
                }
            }
        }
        // find shortest path between 0 and idx i.e level in bfs
        let mut q = VecDeque::<Words>::new();
        let mut seen = vec![false; n + 1];
        q.push_back(Words {id: 0, depth: 1});
        seen[0] = true;
        while !q.is_empty() {
            let word = q.pop_front();
            match word {
                None => break,
                Some(w) => {
                    if w.id == idx as i32 + 1 {
                        return w.depth;
                    }
                    for i in g[w.id as usize].iter() {
                        if !seen[*i as usize] {
                            seen[*i as usize] = true;
                            q.push_back(Words {id: *i, depth: w.depth + 1});
                        }
                    }
                }
            }
        }
        return 0;
    }

    fn worddiff_cnt(a: &str, b: &str) -> i32 {
        a.chars()
            .zip(b.chars())
            .filter(|(ca, cb)| ca != cb)
            .count() as i32
    }
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let beginWord = String::from("hit");
    let endWord = String::from("cog");
    let wordList: Vec<String> = vec![
        "hot".to_string(),
        "dot".to_string(),
        "tog".to_string(),
        "cog".to_string()
    ];
    let ans = Solution::ladder_length(beginWord, endWord, wordList);
    writeln!(wr, "{}", ans).unwrap();
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
