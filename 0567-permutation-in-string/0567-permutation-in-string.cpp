class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> curr(26), track(26);
        for (char c : s1)
            track[c - 'a']++;
        for (int i = 0; i < s2.size(); i++) {
            curr[s2[i] - 'a']++;
            if (i >= s1.size())
                curr[s2[i - s1.size()] - 'a']--;
            if (track == curr)
                return true;
        }
        return false;
    }
};