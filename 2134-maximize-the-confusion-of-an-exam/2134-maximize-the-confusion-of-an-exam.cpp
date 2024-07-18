class Solution {
private:
    int maxChars(string s, int k, char ch) {
        int ct = 0;
        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] != ch)
                ct++;
            while (ct > k) {
                if (s[i] != ch)
                    ct--;
                i++;
            }
            ans = max(ans, (j - i + 1));
        }
        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxChars(answerKey, k, 'T'), maxChars(answerKey, k, 'F'));
    }
};