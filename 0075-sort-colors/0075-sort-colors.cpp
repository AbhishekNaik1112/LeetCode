class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero = 0;
        int one = 0;
        int two = 0;

        for(int x : nums) {
            if(x == 0) {
                zero++;
            } else if(x == 1) {
                one++;
            } else if(x == 2) {
                two++;
            }
        }

        int i = 0;
        while(zero--) {
            nums[i++] = 0;
        }
        while(one--) {
            nums[i++] = 1;
        }
        while(two--) {
            nums[i++] = 2;
        }
    }
};
