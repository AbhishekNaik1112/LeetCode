class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dupes;
        for (auto i : nums)
            dupes[i]++;
        bool flag = false;
        for (auto i : dupes) {
            if (i.second >= 2)
                return true;
        }
        return flag;
    }
};