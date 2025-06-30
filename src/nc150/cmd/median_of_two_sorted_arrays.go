package main

import "math"

func FindMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) == 0 && len(nums2) == 0 {
		return 0
	}

	if len(nums1) > len(nums2) {
		nums1, nums2 = nums2, nums1
	}

	m, n := len(nums1), len(nums2)
	totalLeft := (m + n + 1) / 2

	left, right := 0, m+1

	for left < right {
		cut1 := (left + right) / 2
		cut2 := totalLeft - cut1

		maxLeft1 := math.Inf(-1)
		if cut1 > 0 {
			maxLeft1 = float64(nums1[cut1-1])
		}

		minRight2 := math.Inf(1)
		if cut2 < n {
			minRight2 = float64(nums2[cut2])
		}

		if maxLeft1 <= minRight2 {
			left = cut1 + 1
		} else {
			right = cut1
		}
	}

	cut1 := left - 1
	cut2 := totalLeft - cut1

	maxLeft1 := math.Inf(-1)
	if cut1 > 0 {
		maxLeft1 = float64(nums1[cut1-1])
	}

	minRight1 := math.Inf(1)
	if cut1 < m {
		minRight1 = float64(nums1[cut1])
	}

	maxLeft2 := math.Inf(-1)
	if cut2 > 0 {
		maxLeft2 = float64(nums2[cut2-1])
	}

	minRight2 := math.Inf(1)
	if cut2 < n {
		minRight2 = float64(nums2[cut2])
	}

	if (m+n)%2 == 1 {
		return math.Max(maxLeft1, maxLeft2)
	} else {
		return (math.Max(maxLeft1, maxLeft2) + math.Min(minRight1, minRight2)) / 2.0
	}
}
