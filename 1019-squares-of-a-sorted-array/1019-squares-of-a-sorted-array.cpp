class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n);

        for (int i = 0; i < n; i++)
            prod[i] = nums[i] * nums[i];
        sort(prod.begin(), prod.end());
        return prod;
    }
};