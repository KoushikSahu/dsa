use std::io::{stdin, stdout, BufWriter, prelude::BufRead, prelude::Write};
use std::str;

/*
    Author: Koushik Sahu
    Created: 09:45:26 PM(21:45:26) IST(+05:30) 29-12-2025 Mon
*/

struct Solution {}

impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let (n, m) = (board.len(), board[0].len());
        let mut seen = vec![vec![false; m]; n];
        for i in 0..n {
            for j in 0..m {
                if board[i][j] == 'X' {
                    seen[i][j] = true;
                } else {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) && !seen[i][j] {
                        seen[i][j] = true;
                        Solution::dfs(&i, &j, &mut seen, board);
                    }
                }
            }
        }
        for i in 0..n {
            for j in 0..m {
                if !seen[i][j] {
                    board[i][j] = 'X';
                }
            }
        }
    }

    fn dfs(x: &usize, y: &usize, seen: &mut Vec<Vec<bool>>, board: &mut Vec<Vec<char>>) {
        let dr: Vec<i32> = vec![-1, 1, 0, 0];
        let dc: Vec<i32> = vec![0, 0, -1, 1];
        let (n, m) = (seen.len(), seen[0].len());
        let is_valid = |a: &i32, b: &i32| -> bool {
            return *a >= 0 && *a < n as i32 && *b >= 0 && *b < m as i32;
        };
        for i in 0..4 {
            let r = *x as i32 + dr[i];
            let c = *y as i32 + dc[i];
            if is_valid(&r, &c) && !seen[r as usize][c as usize] && board[r as usize][c as usize] == 'O' {
                seen[r as usize][c as usize] = true;
                let r = r as usize;
                let c = c as usize;
                Solution::dfs(&r, &c, seen, board);
            }
        }
    }
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let mut board = vec![vec!['X','X','X','X'],vec!['X','O','O','X'],vec!['X','X','O','X'],vec!['X','O','X','X']];
    Solution::solve(&mut board);
    for i in 0..board.len() {
        for j in 0..board[0].len() {
            write!(wr, "{} ", board[i][j]).unwrap();
        }
        writeln!(wr).unwrap();
    }
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
