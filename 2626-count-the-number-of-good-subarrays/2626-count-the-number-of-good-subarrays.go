func countGood(nums []int, k int) int64 {
	var rs int64
	n := len(nums)
	mapNumber := make(map[int]int)
	start := 0
	totalPair := 0
	for i := range nums {
		mapNumber[nums[i]]++
		totalPair += mapNumber[nums[i]] - 1
		if totalPair >= k {
			rs += int64(n - i)
			for j := start; j <= i; j++ {
				totalPair -= mapNumber[nums[j]] - 1
				mapNumber[nums[j]]--
				start = j + 1
				if totalPair >= k {
					rs += int64(n - i)
				} else {
					break
				}
			}
		}

	}
	return rs
}