class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize row with all 1s
        for (int i = 1; i <= rowIndex; i++) { // Iterate over each row
            for (int j = i - 1; j > 0; j--) { // Update row values from right to left
                row[j] = row[j] + row[j - 1];
            }
        }
        return row; 
    }
};
