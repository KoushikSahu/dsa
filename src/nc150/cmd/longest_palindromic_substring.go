package main

import (
	"strings"
)

// Longest palindromic substring using dp
func LongestPalindromicSubstring(s string) string {
	n := len(s)
	dp := make([][]bool, n)
	for i := range n {
		dp[i] = make([]bool, n)
	}
	ans := ""
	ans_len := 0
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < n; j++ {
			if i <= j {
				if i == j {
					dp[i][j] = true
					if j-i+1 > ans_len {
						ans_len = j - i + 1
						ans = s[i : j+1]
					}
					continue
				}
				if s[i] == s[j] {
					if i+1 < j {
						dp[i][j] = dp[i+1][j-1]
					} else {
						dp[i][j] = true
					}
					if dp[i][j] {
						if j-i+1 > ans_len {
							ans_len = j - i + 1
							ans = s[i : j+1]
						}
					}
				} else {
					dp[i][j] = false
				}
			}
		}
	}
	return ans
}

func ManachersAlgorithm(s string) string {
	var _s strings.Builder
	_s.WriteRune('$')
	for _, c := range s {
		_s.WriteRune('#')
		_s.WriteRune(c)
	}
	_s.WriteRune('#')
	_s.WriteRune('^')
	s = _s.String()
	l, r := 0, 1
	n := len(s)
	d := make([]int, n)
	for i := 1; i < n-1; i++ {
		d[i] = max(0, min(r-i, d[l+(r-i)]))
		for s[i-d[i]] == s[i+d[i]] {
			d[i] += 1
		}
		if i+d[i] > r {
			l = i - d[i]
			r = i + d[i]
		}
	}
	idx, ans := -1, 0
	for i := 1; i < n-1; i++ {
		if i%2 == 1 {
			tmp := (d[i] / 2) * 2
			if tmp > ans {
				ans = tmp
				idx = i
			}
		} else {
			tmp := (d[i]/2)*2 - 1
			if tmp > ans {
				ans = tmp
				idx = i
			}
		}
	}
	_s1 := s[idx-ans : idx+ans+1]
	var ans_str strings.Builder
	for _, c := range _s1 {
		if c != '#' {
			ans_str.WriteRune(c)
		}
	}
	return ans_str.String()
}
