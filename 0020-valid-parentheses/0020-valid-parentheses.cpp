class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (char c: s) {
            if (c == '(') {
                brackets.push('(');
            } else if (c == ')') {
                if (brackets.empty() || brackets.top() != '(') {
                    return false;
                }
                brackets.pop();
            } else if (c == '{') {
                brackets.push('{');
            } else if (c == '}') {
                if (brackets.empty() || brackets.top() != '{') {
                    return false;
                }
                brackets.pop();
            } else if (c == '[') {
                brackets.push('[');
            } else if (c == ']') {
                if (brackets.empty() || brackets.top() != '[') {
                    return false;
                }
                brackets.pop();
            }
        }
        if (!brackets.empty()) {
            return false;
        }
        return true;
    }
};