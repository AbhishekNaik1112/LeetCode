class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
  const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        // Calculate left: the distance to the previous less element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        // Clear stack for reuse
        while (!s.empty()) s.pop();
        // Calculate right: the distance to the next less or equal element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        // Calculate result using the precomputed left and right arrays
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return (int)result;
    }
};