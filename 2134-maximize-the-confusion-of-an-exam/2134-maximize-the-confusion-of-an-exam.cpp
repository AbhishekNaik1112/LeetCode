class Solution {

private:
    int maxChars(string s, char ch, int k) {
        int ans = 0;
        int i = 0;
        int ct = 0;

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
        int char1 = maxChars(answerKey, 'T', k);
        int char2 = maxChars(answerKey, 'F', k);

        return max(char1, char2);
    }
};