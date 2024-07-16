class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end()); // sort tokens
        int res = 0, points = 0;
        int i = 0, j = tokens.size() - 1; // i=left, j=right
        
        while (i <= j) { // left<=right
            if (power >= tokens[i]) { // enough power for playing?
                power -= tokens[i++]; // reduce power, move left pointer
                res = max(res, ++points); // increase points, update res
            } else if (points > 0) { // not enough power but have points?
                points--; // give up points
                power += tokens[j--]; // gain power, move right pointer
            } else {
                break; // cannot play anymore
            }
        }
        return res; // return max score
    }
};

// -----------
// |Recursive|
// -----------

// class Solution {
// public:
//     int solve(vector<int>& tokens, int power,int index){
//         if(index >= tokens.size()) return 0;

//         int score = INT_MIN;
//         if(power >= tokens[index]) score = 1 + solve(tokens, power - tokens[index], index + 1);
//         score = max(score, solve(tokens, power, index + 1));

//         if(score != 0) score = max(score, solve(tokens, power + tokens[index], index + 1) - 1);
//         return score;
//     }
//     int bagOfTokensScore(vector<int>& tokens, int power) {
//         sort(tokens.begin(), tokens.end(), greater<int>());
//         return solve(tokens, power, 0);
//     }
// };