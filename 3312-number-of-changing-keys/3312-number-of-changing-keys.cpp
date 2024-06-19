class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.size();
        int ct = 0;
        for (int i = 0; i < n; i++)
            s[i] = tolower(s[i]);
        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i])
                ct++;
        }
        return ct;
    }
};