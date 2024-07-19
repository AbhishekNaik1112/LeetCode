class Solution {
    private:
    int maxChars(string s ,int k,char ch){
            int ct =0;
        int ans = 0;
        int i=0;

        for(int j=0;j<s.size();j++){
            if(s[j]!=ch) ct++;
            while(ct>k){
                if(s[i]!=ch)
                    ct--;
                i++;
            }
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
    int c1=maxChars(answerKey,k,'T');
    int c2=maxChars(answerKey,k,'F');
    // cout<<c1<<" "<<c2;
    return max(c1,c2);
    }
};