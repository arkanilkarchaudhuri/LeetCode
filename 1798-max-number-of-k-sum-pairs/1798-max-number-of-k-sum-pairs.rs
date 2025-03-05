impl Solution {
    pub fn max_operations(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let mut left = 0;
        let mut right = nums.len() - 1;
        let mut result = 0;
        
        while left < right {
            let sum = nums[left] + nums[right];
            if sum == k {
                result += 1;
                left += 1;
                right -= 1;
            }
            else if sum < k { left += 1; }
            else { right -= 1; }
        }
        
        return result;        
    }
}