class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (ch == ')' && !st.empty() && st.top() == '(' ||
                       ch == ']' && !st.empty() && st.top() == '[' ||
                       ch == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};