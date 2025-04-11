package main

func LongestSubstringWithoutRepeatingCharacters(s string) int {
	if len(s) == 0 {
		return 0
	}

	runes := ([]rune)(s)

	lst_idx := make(map[rune]int)
	lst_idx[runes[0]] = 0
	lst := 1
	ans := 1

	for i := 1; i < len(s); i++ {
		val, exists := lst_idx[runes[i]]
		curr := 0
		if exists {
			if val < i-lst {
				curr = lst + 1
			} else {
				curr = i - val
			}
		} else {
			curr = lst + 1
		}
		lst_idx[runes[i]] = i
		lst = curr
		ans = max(ans, curr)
	}
	return ans
}
