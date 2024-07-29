class Solution {
public:
    vector<string> result;
    void helper(int o, int c, int n, string curr) {
        if (curr.length() == n * 2) {
            result.push_back(curr);
            return;
        }
        if (o < n)
            helper(o + 1, c, n, curr + "(");
        if (c < o)
            helper(o, c + 1, n, curr + ")");
    }
    vector<string> generateParenthesis(int n) {
        helper(0, 0, n, "");
        return result;
    }
};