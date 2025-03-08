class Solution {
public:
    
    int countWithMergeSort(vector<long> &sums, int left, int right, int lower, int upper)
    {
        int count = 0;
        
        if(right - left <= 1)
        {
            if(right - left == 1)
            {
                return (lower <= sums[left] && sums[left] <= upper);
            }
            else
            {
                return 0;
            }
        }
        
        int mid = (left + right)/2;
        
        int leftSideSum = countWithMergeSort(sums, left, mid, lower, upper);
        int rightSideSum = countWithMergeSort(sums, mid, right, lower, upper);
        
        
        int i = left;
        int j = mid;
        
        int n = 0;
        int m = 0;
        
        vector<long> cache(right - left, 0);
        
        int k = 0;
        
        
        while(i < mid)
        {
            

            while(mid+n < right && sums[mid+n] < sums[i]+lower)
                {
                    n++;
                }
            
            while(mid+m < right && sums[mid+m] <= sums[i] + upper)
                {
                    m++;
                }
            
            while(j < right && sums[j] < sums[i])
            {
                cache[k++] = sums[j++];
            }
            
            cache[k++] = sums[i++];
            
            count += m-n;
        }
        
        
        while(j < right)
        {
            cache[k++] = sums[j++];
        }
        
        
        for(int idx = 0; idx<cache.size(); idx++)
        {
            sums[left + idx] = cache[idx];
        }
    
        return leftSideSum + rightSideSum + count;
        
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        vector<long> prefixSum(nums.size(),0);
        
        int n = nums.size();
        
        prefixSum[0] = nums[0];
        
        for(int i = 1; i<nums.size(); i++)
        {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        
        return countWithMergeSort(prefixSum, 0, n, lower, upper);
    }
};