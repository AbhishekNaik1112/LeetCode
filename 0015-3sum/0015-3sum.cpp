class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> num1;
        sort(nums.begin(), nums.end()); // sorting the array

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { // skipping dupes
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1; // two pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // finding sum

                if (sum > 0) { // if sum>0 move k pointer left
                    k--;
                } else if (sum < 0) { // if sum<0 move j pointer right
                    j++;
                } else {
                    num1.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // skip dupes
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // skip dupes
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return num1;
    }
};