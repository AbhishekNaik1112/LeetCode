class Solution {
public:
    int rec(vector<int>& nums, int start, int end) {
        if (start > end) {
            return 0;
        }

        int c1 = nums[start] +
                 min(rec(nums, start + 2, end), rec(nums, start + 1, end - 1));
        int c2 = nums[end] +
                 min(rec(nums, start + 1, end - 1), rec(nums, start, end - 2));

        return max(c1, c2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int best = rec(nums, 0, n - 1);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (best >= sum - best) {
            return true;
        }
        return false;
    }
};