class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> results(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            int high = potions.size() - 1;
            int low = 0;
            int mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if ((long long)spells[i] * (long long)potions[mid] >= success) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            results[i] = potions.size() - low;
        }
        return results;
    }
};
