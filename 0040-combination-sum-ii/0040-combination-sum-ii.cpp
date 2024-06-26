class Solution {

private:
    void helper(int index, int target, vector<int>& candidates,
                vector<vector<int>>& ans, vector<int>& temp) {
        if (target ==
            0) { // base case i.e while substracting from index element we stop
            ans.push_back(temp); // push valid ones to ans
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) // index element more than target
                break;
            if (i > index &&
                candidates[i] == candidates[i - 1]) // if prev element and next
                                                    // element are same skip it
                continue;
            temp.push_back(candidates[i]);
            helper(i + 1, target - candidates[i], candidates, ans,
                   temp); // recursive fx
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort given array
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, target, candidates, ans, temp);
        return ans;
    }
};