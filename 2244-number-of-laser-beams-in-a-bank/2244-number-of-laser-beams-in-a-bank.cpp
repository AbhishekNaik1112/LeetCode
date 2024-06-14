class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pct = 0, tot = 0;

        for (const string& row : bank) {
            int curr = count(row.begin(), row.end(), '1');
            if (curr > 0) {
                tot += pct * curr;
                pct = curr;
            }
        }

        return tot;
    }
};
