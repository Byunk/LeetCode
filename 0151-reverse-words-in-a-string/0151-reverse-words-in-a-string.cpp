class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        
        int pt = 0;
        while (pt < s.length()) {
            if (s[pt] == ' ') {
                ++pt;
            } else {
                string word = "";
                while (pt < s.length() && s[pt] != ' ') {
                    word += s[pt];
                    ++pt;
                }
                
                words.push(word);
            }
        }
        
        string ret = "";
        while (!words.empty()) {
            ret += words.top();
            ret += " ";
            words.pop();
        }
        
        return ret.substr(0, ret.length()-1);
    }
};