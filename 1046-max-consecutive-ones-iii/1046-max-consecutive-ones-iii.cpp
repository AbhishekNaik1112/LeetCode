class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }
            if (k < 0) { //if all flips used
                if (nums[i] == 0) { // remove it from the window
                    k++; // and increment k as we expand the window
                }
                i++; // shrink window
            }
            j++; // expand window
        }
        return (j-i);
    }
};