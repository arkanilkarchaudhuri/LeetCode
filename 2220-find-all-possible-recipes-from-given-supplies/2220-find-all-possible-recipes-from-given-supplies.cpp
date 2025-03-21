class Solution {
public:
    bool find(vector<string>& recipes, int indx, vector<vector<string>>& ingredients, unordered_set<string>& curr, vector<string>& result, vector<int>& arr, unordered_map<string, int>& reci) {
        if (arr[indx] == -1) return false;
        if (arr[indx] == 1) return true;
        
        arr[indx] = -1;
        for (const string& ingred : ingredients[indx]) {
            if (!curr.count(ingred)) {
                if (!reci.count(ingred) || !find(recipes, reci[ingred], ingredients, curr, result, arr, reci)) {
                    arr[indx] = -1;
                    return false;
                }
            }
        }
        
        arr[indx] = 1;
        curr.insert(recipes[indx]);
        result.push_back(recipes[indx]);
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;
        unordered_map<string, int> reci;
        unordered_set<string> curr(supplies.begin(), supplies.end());
        vector<int> arr(n, 0);
        
        for (int i = 0; i < n; i++) {
            reci[recipes[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                find(recipes, i, ingredients, curr, result, arr, reci);
            }
        }

        return result;
    }
};