class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // using greedy

        // sort both arrays
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // size of each array
        int gs = g.size();
        int ss = s.size();

        // make a count
        int ct = 0;

        // initial index
        int i = 0;
        int j = 0;

        // run loop till one reaches the end
        while (i < gs && j < ss) {
            // to satisfy curr child
            if (s[j] >= g[i]) {
                ct++; // increment
                i++;  // next child
            }
            j++; // next cookie
        }
        return ct;  //return count
    }
};