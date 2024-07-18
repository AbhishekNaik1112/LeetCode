class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > op = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        stack<int> stack;
        for (string& s : tokens) {
            if (!op.count(s)) {
                stack.push(stoi(s));
            } else {
                int n1 = stack.top();
                stack.pop();
                int n2 = stack.top();
                stack.pop();
                stack.push(op[s](n2, n1));
            }
        }
        return stack.top();
    }
};