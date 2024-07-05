class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t posi = s.find(part);
        while (posi != string::npos) {
            s.erase(posi, part.length());
            posi = s.find(part);
        }
        return s;
    }
};