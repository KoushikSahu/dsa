package solutions

import (
	"errors"
)

func TwoSums(nums []int, target int) ([]int, error) {
	n := len(nums)
	seen := make(map[int]int)

	for i := range n {
		complement := target - nums[i]
		value, exists := seen[complement]
		if exists {
			return []int{value, i}, nil
		}
		seen[nums[i]] = i
	}
	return []int{}, errors.New("no solution")
}
