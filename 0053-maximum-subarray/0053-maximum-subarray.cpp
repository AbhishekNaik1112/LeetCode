class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxAns = INT_MIN;  //-1000
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];


            if (curr > maxAns)
                maxAns = curr;
                
            if (curr < 0)
                curr = 0;
        }
        return maxAns;
    }
};

