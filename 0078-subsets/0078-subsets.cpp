class Solution {
    void helper(int start, vector<int>& nums, vector<int>& curr,
                vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            helper(i + 1, nums, curr, res);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        helper(0, nums, curr, res);
        return res;
    }
};