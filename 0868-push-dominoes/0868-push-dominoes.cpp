class Solution {
public:
    string pushDominoes(string dominoes) {
        string temp;

        while (dominoes != temp) {
            temp = dominoes;
            
            // Step 1: Replace "R.L" with "xxx"
            for (size_t pos = 0; (pos = dominoes.find("R.L", pos)) != string::npos; pos += 3) {
                dominoes.replace(pos, 3, "xxx");
            }
            // Step 2: Replace "R." with "RR"
            for (size_t pos = 0; (pos = dominoes.find("R.", pos)) != string::npos; pos += 2) {
                dominoes.replace(pos, 2, "RR");
            }
            // Step 2: Replace ".L" with "LL"
            for (size_t pos = 0; (pos = dominoes.find(".L", pos)) != string::npos; pos += 2) {
                dominoes.replace(pos, 2, "LL");
            }
        }
        // Step 3: Replace "xxx" with "R.L"
        for (size_t pos = 0; (pos = dominoes.find("xxx", pos)) != string::npos; pos += 3) {
            dominoes.replace(pos, 3, "R.L");
        }  
        return dominoes;
    }
};
