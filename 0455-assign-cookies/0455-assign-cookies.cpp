class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gs = g.size();
        int ss = s.size();

        int i = 0;
        int j = 0;

        int ct = 0;

        while (i < gs && j < ss) {
            if (g[i] >= s[j]) {
                ct++;
                i++;

                j++;
            }
        }
        return ct;
    }
};