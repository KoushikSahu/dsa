package main

import (
	"math"
	"strconv"
)

func lte(a []rune, b string) bool {
	if len(a) < len(b) {
		return true
	} else if len(a) > len(b) {
		return false
	}
	for i := range a {
		if a[i] < rune(b[i]) {
			return true
		} else if a[i] > rune(b[i]) {
			return false
		}
	}
	return false
}

func ReverseInteger(x int) int {
	is_negative := x < 0
	if is_negative {
		x *= -1
	}
	xstr := []rune{}
	for _, c := range strconv.Itoa(x) {
		xstr = append(xstr, c)
	}
	l, h := 0, len(xstr)-1
	for l < h {
		xstr[l], xstr[h] = xstr[h], xstr[l]
		l += 1
		h -= 1
	}
	if is_negative {
		if lte(xstr, strconv.Itoa(int(math.Pow(2, 31)))) {
			xcomb := ""
			for _, c := range xstr {
				xcomb += string(c)
			}
			val, err := strconv.Atoi("-" + xcomb)
			if err == nil {
				return val
			} else {
				panic(err)
			}
		} else {
			return 0
		}
	} else {
		if lte(xstr, strconv.Itoa(int(math.Pow(2, 31))-1)) {
			xcomb := ""
			for _, c := range xstr {
				xcomb += string(c)
			}
			val, err := strconv.Atoi(xcomb)
			if err == nil {
				return val
			} else {
				panic(err)
			}
		} else {
			return 0
		}
	}
}

func ReverseInteger1(x int) int {
	is_negative := x < 0
	if is_negative {
		x *= -1
	}
	ans := 0
	for x != 0 {
		if ans > math.MaxInt/10 {
			return 0
		}
		ans *= 10
		rem := x % 10
		if is_negative {
			if ans-rem-1 > (math.MinInt32+1)*-1 {
				return 0
			}
		} else {
			if ans > math.MaxInt-rem {
				return 0
			}
		}
		ans += rem
		x /= 10
	}
	if is_negative {
		ans *= -1
	}
	return ans
}
