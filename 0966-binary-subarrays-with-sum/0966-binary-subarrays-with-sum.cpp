class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> ct;
        ct[0] = 1;
        int sum = 0;
        int total = 0;

        for (int num : nums) {
            sum += num;
            if (ct.find(sum - goal) != ct.end()) {
                total += ct[sum - goal];
            }
            ct[sum]++;
        }

        return total;
    }
};