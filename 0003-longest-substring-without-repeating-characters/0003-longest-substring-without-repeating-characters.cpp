class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;

        unordered_map<char, int> seen;

        for (int right = 0; right < s.size(); right++) {
            char curr = s[right];
            if (seen.find(curr) != seen.end() && seen[curr] >= left) {
                left = seen[curr] + 1;
            }
            seen[curr] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};