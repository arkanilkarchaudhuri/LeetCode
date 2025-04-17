impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut result = 0;
        for idx in 0..nums.len() {
            for idx1 in idx+1..nums.len() {
                if nums[idx] == nums[idx1] && (idx*idx1) % k as usize == 0 {
                    result += 1;
                }
            }
        }
        result
    }
}