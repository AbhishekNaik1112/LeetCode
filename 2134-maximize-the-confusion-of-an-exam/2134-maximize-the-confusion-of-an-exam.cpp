class Solution {
public:
   int maxChars(string answerKey, char ch, int k) {
    int len = 0;
    int i = 0;
    int ct = 0;

    for (int j = 0; j < answerKey.size(); j++) {
        if (answerKey[j] != ch)
            ct++;
        while (ct > k) {
            if (answerKey[i] != ch) {
                ct--;
            }
            i++;
        }
        len = max(len, j - i + 1);
    }
    return len;
}

int maxConsecutiveAnswers(string answerKey, int k) {
    return max(maxChars(answerKey, 'T', k), maxChars(answerKey, 'F', k));
}
};