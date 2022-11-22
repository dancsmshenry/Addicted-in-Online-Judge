func max(i int, j int) int {
	if i <= j {
		return j
	}
	return i
}

func lengthOfLongestSubstring(s string) int {
	if len(s) < 2 {
		return len(s)
	}
	map_ := make(map[byte]int)
	j := 1
	res := 1
	for i := 0; i < len(s); i++ {
		if i == 0 {
			map_[s[i]] = 1
		} else {
			delete(map_, s[i-1])
		}
		for j < len(s) && map_[s[j]] == 0 { //  map中没有的元素，默认是零值
			map_[s[j]] = 1
			j++
		}
		res = max(res, j-i)
	}
	return res
}