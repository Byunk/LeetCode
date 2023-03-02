class Solution {
public:
    int compress(vector<char>& chars) {
        // two pointers
        int l = 0, r = 0;

        while (r < chars.size() - 1) {
            // compare r & r+1 elements
            if (chars[r] == chars[r+1]) {
                r++;
            } else {
                if (r == l) {
                    // only one elment exists
                    ++r;
                    ++l;
                } else {
                    int cnt = r-l+1;
                    string s = to_string(cnt);
                    for (int i = 0; i < s.size(); i++) {
                        chars[++l] = s[i];
                    }
                    chars.erase(chars.begin() + ++l, chars.begin() + ++r);
                    r = l;
                }
            }
        }
        
        if (r != l) {
            int cnt = r-l+1;
            string s = to_string(cnt);
            for (int i = 0; i < s.size(); i++) {
                chars[++l] = s[i];
            }
            chars.erase(chars.begin() + ++l, chars.begin() + ++r);
            r = l;
        }

        return chars.size();
    }
};