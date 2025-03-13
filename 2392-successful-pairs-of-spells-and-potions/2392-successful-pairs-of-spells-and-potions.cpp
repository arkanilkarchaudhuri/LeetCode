class Solution {
public:
    // T:O(m log m + n log m), S:O(log m)
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> numPairs(spells.size(), 0);

        // Sort potions
        sort(potions.begin(), potions.end()); // O(m log m)

        // Loop through all spells
        for(int i = 0; i < spells.size(); i++) { // O(n)
            // Find the minimum potion needed for success
            long long potionNeeded = ceil(static_cast<double>(success) / spells[i]);

            // Find the smallest idx position
            auto it = lower_bound(potions.begin(), potions.end(), potionNeeded); // O(log m)
            int idx = it - potions.begin();

            // Calculate count based on the index
            int numPair = potions.size() - (it - potions.begin());
            numPairs[i] = max(0, numPair);
        }

        return numPairs;
    }
};