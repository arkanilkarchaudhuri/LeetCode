impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum = nums.iter().sum::<i32>();
        if sum % 2 == 1 { return false }
        let target = sum / 2;

        Self::can_form(nums, target)
    }

    fn can_form(nums: Vec<i32>, target: i32) -> bool {
        let target = target as usize;
        let n = nums.len();
        let mut dp = vec![vec![false; target + 1]; n + 1];
        for z in 0..=n { dp[z][0] = true }
        for i in 1..=n {
            for j in 1..=target {
                if nums[i - 1] > j as i32 {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1] as usize];
                }
            }
        }

        dp[n][target]
    }
}