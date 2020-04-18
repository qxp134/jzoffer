func twoSum(nums []int, target int) []int {
	ans := make([]int ,2 , 2)
	map1 := make(map[int]int)
	for i,v := range nums{
		value,yes := map1[target - v]
		map1[v] = i
		if yes{
			ans[0] = value
			ans[1] = i
			return ans
		}
	}
	return ans
}
