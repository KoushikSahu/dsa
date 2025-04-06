use std::io::{prelude::BufRead, prelude::Write, stdin, stdout, BufWriter};
use std::str;

/*
    Author: Koushik Sahu
    Created: 12:08:25 PM(12:08:25) IST(+05:30) 27-06-2024 Thu
*/

fn binary_search(a: &Vec<i32>, x: i32) -> usize {
    let (mut l, mut h) = (0 as usize, a.len());
    while l < h {
        let mid = l + ((h - l) >> 1);
        if a[mid] < x {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    l
}

fn solve<R: BufRead, W: Write>(sc: &mut Scanner<R>, wr: &mut W) {
    let a = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let x = 7;
    writeln!(wr, "{}", binary_search(&a, x)).unwrap();
}

#[test]
fn test1() {
    let a = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let x = 7;
    assert_eq!(binary_search(&a, x), 6);
}

#[test]
fn test2() {
    let a = Vec::<i32>::new();
    let x = 7;
    assert_eq!(binary_search(&a, x), 0);
}

#[test]
fn test3() {
    let a = vec![1, 2, 3, 4, 5];
    let x = 7;
    assert_eq!(binary_search(&a, x), 5);
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
}

fn main() {
    let (stdin, stdout) = (stdin(), stdout());
    let mut scan = Scanner::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());
    #[allow(unused_variables)]
    let t: i32 = 1;
    // let t: i32 = scan.next();
    for _ in 0..t {
        solve(&mut scan, &mut out);
    }
}
