class Solution {
public:
    int calculate(string s) {

        stack <long long> nums, signs;

        long long num = 0;
        long long res = 0;
        long long sign = 1;

        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                res += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(res);
                    signs.push(sign);
                    res = 0;
                    sign = 1;
                }
                if (c == ')' && signs.size()) {
                    res = signs.top() * res + nums.top();
                    signs.pop(); 
                    nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};