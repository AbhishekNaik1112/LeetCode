class Solution {
public:
    long long calculate(string s) {
        stack <long long> nums, ops;
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
                    ops.push(sign);
                    res = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    res = ops.top() * res + nums.top();
                    ops.pop(); 
                    nums.pop();
                }
            }
        }
        res += sign * num;
        return res;
    }
};