class Solution {
    void helper(int index, vector<int>& nums, vector<int>& temp,
                vector<vector<int>>& ans) {
        // add curr subset
        ans.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            // skip dupes
            if (i != index && nums[i] == nums[i - 1])
                continue;
            // curr el in curr subset
            temp.push_back(nums[i]);
            // +1 index
            helper(i + 1, nums, temp, ans);
            // bktk remove used el
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;        // storing subsets
        vector<int> temp;               // temp
        sort(nums.begin(), nums.end()); // sort ip
        helper(0, nums, temp, ans);
        return ans;
    }
};
