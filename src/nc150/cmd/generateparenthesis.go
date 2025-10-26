package main

func generateParenthesisRecurse(net int, opening int, closing int) []string {
	ans := []string {}
	if opening == 0 && closing == 0 {
		return []string {""}
	}
	if opening > 0 {
		possibilities := generateParenthesisRecurse(net + 1, opening - 1, closing)
		for _, val := range possibilities {
			ans = append(ans, "(" + val)
		}
	}
	if closing > 0 && net > 0 {
		possibilities := generateParenthesisRecurse(net - 1, opening, closing - 1)
		for _, val := range possibilities {
			ans = append(ans, ")" + val)
		}
	}
	return ans
}

func generateParenthesis(n int) []string {
	return generateParenthesisRecurse(0, n, n)
}
