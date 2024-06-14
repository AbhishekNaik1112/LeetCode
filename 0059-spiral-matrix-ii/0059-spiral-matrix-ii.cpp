class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;

        int value = 1;

        while (value <= n * n) {
            // right
            for (int i = left; i <= right; i++) {
                matrix[top][i] = value++;
            }
            top++;
            // down
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = value++;
            }
            right--;
            // left
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = value++;
            }
            bottom--;
            // up
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = value++;
            }
            left++;
        }

        return matrix;
    }
};