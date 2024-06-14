class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long even = 0;
        long odd =0;

        for(int x : nums){
            even=max(even,odd+x);
            odd=max(odd,even-x);
        }
        return max(even,odd);
        
    }
};