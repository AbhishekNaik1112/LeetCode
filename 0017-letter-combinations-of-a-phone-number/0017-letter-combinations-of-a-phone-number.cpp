class Solution {
public:
    void helper(int index, string& digits, string& temp, vector<string>& ans,
                const unordered_map<char, string>& phone) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        char digit = digits[index];
        const string& letters = phone.at(digit);
        for (char letter : letters) {
            temp.push_back(letter);
            helper(index + 1, digits, temp, ans, phone);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };

        if (digits.empty())
            return {}; // edge case

        vector<string> ans;
        string temp;
        helper(0, digits, temp, ans, phone); // index,digits,temp,phone,ans
        return ans;
    }
};