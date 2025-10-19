package main

import "sort"

func threeSum(nums []int) [][]int {
	mp := make(map[int]bool)
	ans_mp := map[[3]int]bool{}
	ans := [][]int{}
	for i := 0; i < len(nums) - 1; i++ {
		for j := i + 1; j < len(nums); j++ {
			rem := - (nums[i] + nums[j])
			_, ok := mp[rem]
			if ok {
				tmp := [3]int{rem, nums[i], nums[j]}
				sort.Ints(tmp[:])
				_, ok1 := ans_mp[tmp]
				if !ok1 {
					ans = append(ans, tmp[:])
				}
				ans_mp[tmp] = true
			}
		}
		mp[nums[i]] = true
	}
	return ans
}
