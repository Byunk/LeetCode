class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0; // haystack pointer
        
        for (; i < haystack.size(); i++) {
            int j = 0;
            while ((i + j) < haystack.size() && haystack[i + j] == needle[j]) {
                j++;
                if (j == needle.size()) {
                    return i;
                }
            }
        }
        return -1;
    }
};