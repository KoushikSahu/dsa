package main

func IsValid(s string) bool {
	st := []rune{}
	for _, c := range s {
		if c == '(' || c == '[' || c == '{' {
			st = append(st, c)
		} else {
			l := len(st)
			if l == 0 {
				return false
			}
			ch := st[l-1]
			st = st[:l-1]
			if (c == ')' && ch != '(') ||
				(c == ']' && ch != '[') ||
				(c == '}' && ch != '{') {
				return false
			}
		}
	}
	return len(st) == 0
}
