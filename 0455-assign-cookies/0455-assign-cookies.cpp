class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gs = g.size();
        int ss = s.size();
        int ct = 0;
        int i = 0;
        int j = 0;
        while (i < gs && j < ss) {
            if (s[j] >= g[i]) {
                ct++;
                i++;
            }
            j++;
        }
        return ct;
    }
};