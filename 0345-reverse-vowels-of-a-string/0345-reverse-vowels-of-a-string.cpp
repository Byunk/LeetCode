class Solution {
public:
    string reverseVowels(string s) {
        // two pointers
        int l = 0; int r = s.length() - 1;
        
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        while (l < r) {
            while (l < s.length() && find(begin(vowels), end(vowels), s[l]) == end(vowels)) {
                ++l;
            }
            while (r >= 0 && find(begin(vowels), end(vowels), s[r]) == end(vowels)) {
                --r;
            }
            
            if (l < r) {
                swap(s[l], s[r]);    
                ++l;
                --r;
            }
        }
        return s;
    }
};