class Solution {

    private:
    int maxChars(string answerKey, int k,char ch){
        int ct=0;
        int ans = 0;
        int i=0;

        for(int j=0;j<answerKey.size();j++){
            if(answerKey[j]!=ch) ct++;
            while(ct>k){
                if(answerKey[i]!=ch) 
                    ct--;
                i++;
            }
                ans = max(ans,(j-i+1));
            }
            return ans;
        }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int char1 = maxChars(answerKey,k,'T');
        int char2 = maxChars(answerKey,k,'F');

        return max(char1,char2);
    }
};