class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> curr(26), tracker(26);

        for (char ch : s1)
            tracker[ch - 'a']++;

        for (int i = 0; i < s2.size(); i++) {
            curr[s2[i] - 'a']++;

            if (i >= s1.size())
                curr[s2[i - s1.size()] - 'a']--;

            if (tracker == curr)
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         vector<int> curr(26), tracker(26);
//         for (char c : s1)
//             tracker[c - 'a']++;
//         for (int i = 0; i < s2.size(); i++) {
//             curr[s2[i] - 'a']++;
//             if (i >= s1.size())
//                 curr[s2[i - s1.size()] - 'a']--;
//             if (tracker == curr)
//                 return true;
//         }
//         return false;
//     }
// };