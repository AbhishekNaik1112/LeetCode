class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> op = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}};
        stack<int> st;

        for (string& s : tokens) {
            if (!op.count(s)) {
                st.push(stoi(s));
            } else {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(op[s](n2, n1));
            }
        }
        return st.top();
    }
};