class Solution {
    public int minOperations(int[] nums) {
        int n=nums.length, c=0;

        for(int i=0; i<n; i++){
            if((i==n-1 || i==n-2) && (nums[i]==0)){
                return -1;
            }

            else if(nums[i]==0){
                nums[i] = 1;
                nums[i+1] = (nums[i+1]==0) ? 1 : 0;
                nums[i+2] = (nums[i+2]==0) ? 1 : 0;
                c++;
            }
        }

        return c;
    }
}