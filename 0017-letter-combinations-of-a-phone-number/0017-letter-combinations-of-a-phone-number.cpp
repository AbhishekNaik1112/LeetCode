class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        vector<string> ans;
        if (digits.empty()) {
            return ans; 
        }
        ans.push_back(""); 

        for (char digit : digits) {
            const string& letters = phone[digit];
            vector<string> new_combinations;
            for (const string& combination : ans) {
                for (char letter : letters) {
                    new_combinations.push_back(combination + letter);
                }
            }
            ans = move(new_combinations);
        }

        return ans;
    }
};