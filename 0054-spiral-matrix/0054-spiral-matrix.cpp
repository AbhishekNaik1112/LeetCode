class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        if (matrix.empty() || matrix[0].empty())  //edge case maybe
            return spiral;

        int r = matrix.size();
        int c = matrix[0].size();
        
        int el = r * c; //total elements
        
        //bounds
        int top = 0;
        int bot = r - 1;
        int right = c - 1;
        int left = 0;

        int ct = 0;

        while (ct < el) {
            // left to right 
            for (int i = left; i <= right && ct < el; i++) {
                spiral.push_back(matrix[top][i]);
                ct++;
            }
            top++;

        //    toip to bot
            for (int i = top; i <= bot && ct < el; i++) {
                spiral.push_back(matrix[i][right]);
                ct++;
            }
            right--;

        //    right to left
            for (int i = right; i >= left && ct < el; i--) {
                spiral.push_back(matrix[bot][i]);
                ct++;
            }
            bot--;

        //  bot to top
            for (int i = bot; i >= top && ct < el; i--) {
                spiral.push_back(matrix[i][left]);
                ct++;
            }
            left++;
        }

        return spiral;
    }
};
