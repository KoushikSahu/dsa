package main

// maximize |i - j| * min(height[i], height[j]) in O(nlog(n)) time

func maxArea(height []int) int {
	i := 0
	j := len(height) - 1
	curr := (j-i) * min(height[i], height[j])
	for i < j {
		if height[i] < height[j] {
			curr_h := height[i]
			for i < j {
				i += 1
				if curr_h < height[i] {
					break
				}
			}
			curr = max(curr, (j - i) * min(height[j], height[i]))
		} else {
			curr_h := height[j]
			for i < j {
				j -= 1
				if curr_h < height[j] {
					break
				}
			}
			curr = max(curr, (j - i) * min(height[j], height[i]))
		}
	}
	return curr
}
