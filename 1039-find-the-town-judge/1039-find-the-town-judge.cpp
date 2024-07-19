class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ct(n + 1, 0);
        for (auto& it : trust)
            ct[it[0]]--, ct[it[1]]++;
        for (int i = 1; i <= n; i++)
            if (ct[i] == n-1)
                return i;
        return -1;
    }
};