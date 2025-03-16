class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long low = 1, high = (long long)*max_element(ranks.begin(), ranks.end()) * cars * cars, mid;
        long long ans = high;

        auto isFeasible = [&](long long time) {
            int repaired = 0;
            for(auto rank : ranks)
            {
                repaired += floor(sqrt(time / rank));
                if(repaired >= cars)
                    return true;
            }
            return false;
        };

        while(low < high)
        {
            mid = (low + high) / 2;
            if(isFeasible(mid))
            {
                high = mid;
                ans = min(ans, high);
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};