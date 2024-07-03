class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ct = 0;
        for (int x : arr) {
            if (x % 2 != 0) {
                ct++;
                if (ct == 3) return true;
            } else ct = 0;
        }
        return false;
    }
};