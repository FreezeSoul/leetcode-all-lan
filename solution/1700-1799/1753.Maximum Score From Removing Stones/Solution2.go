func maximumScore(a int, b int, c int) int {
	s := []int{a, b, c}
	sort.Ints(s)
	if s[0]+s[1] < s[2] {
		return s[0] + s[1]
	}
	return (a + b + c) >> 1
}