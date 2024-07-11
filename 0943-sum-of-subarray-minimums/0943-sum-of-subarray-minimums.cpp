class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        int n = arr.size();
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int min_val = arr[i];
            for (int j = i; j < n; ++j) {
                min_val = min(min_val, arr[j]);
                result = (result + min_val) % MOD;
            }
        }
        return (int)result;
    }
};
    }
};