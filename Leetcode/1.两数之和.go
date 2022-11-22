func twoSum(nums []int, target int) []int {
    map_ := make(map[int]int)
    
    for i, v := range nums {
        if _, state := map_[target - v]; state {
            return []int{map_[target - v], i}
        }
        map_[v] = i
    }

    return nil
}