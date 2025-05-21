package main

import (
	"sort"
)

func Change(amount int, coins []int) int {
	sort.Ints(coins)
	dp := make([][]int, amount+1)
	n := len(coins)
	for i := range amount + 1 {
		dp[i] = make([]int, n+1)
	}
	for i := range n + 1 {
		dp[0][i] = 1
	}
	for i := 1; i <= amount; i += 1 {
		for j := 1; j <= n; j += 1 {
			if coins[j-1] <= i {
				dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1]
			} else {
				dp[i][j] = dp[i][j-1]
			}
		}
	}
	return dp[amount][n]
}
