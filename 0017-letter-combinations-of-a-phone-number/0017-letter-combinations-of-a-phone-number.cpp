class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        vector<string> ans;
        vector<string> temp;

        if (digits.empty()) {
            return ans;
        }
        ans.push_back("");

        for (char digit : digits) {
            const string letters = phone[digit];
            for (const string x : ans) {
                for (char letter : letters) {
                    temp.push_back(x + letter);
                }
            }
            ans = move(temp);
        }

        return ans;
    }
};