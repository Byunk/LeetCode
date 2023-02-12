class Solution {
private:
    vector<int> multiply_one_digit(string& num1, char& num2digit, int digit) {
        vector<int> result;
        // add leading zeros;
        for (int i = 0; i < digit; i++) {
            result.push_back(0);
        }

        // multiply num1 and num2 digit
        int carry = 0;
        int n2 = num2digit - '0';
        for (char num1digit: num1) {
            int mult = (num1digit - '0') * n2 + carry;
            result.push_back(mult % 10);
            carry = mult / 10;
        }

        if (carry != 0) {
            result.push_back(carry);
        }
        return result;
    }

    vector<int> add_vectors(vector<int>& v1, vector<int>& v2) {
        vector<int> result;
        int flag = 0;
        for (int i = 0; i < v1.size() || i < v2.size() || flag != 0; i++) {
            if (i >= v1.size() && i >= v2.size()) {
                result.push_back(flag);
                flag = 0;
                continue;
            }
            if (i >= v1.size()) {
                int add = v2[i] + flag;
                result.push_back(add % 10);
                flag = add / 10;
                continue;
            } else if (i >= v2.size()) {
                int add = v1[i] + flag;
                result.push_back(add % 10);
                flag = add / 10;
                continue;
            }

            int add = v1[i] + v2[i] + flag;
            result.push_back(add % 10);
            flag = add / 10;
        }
        return result;
    }

public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> ans;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num2.size(); i++) {
            vector<int> v = multiply_one_digit(num1, num2[i], i);
            ans = add_vectors(ans, v);
        }
        reverse(ans.begin(), ans.end());
        string s;
        for (int i = 0; i < ans.size(); i++) {
            s += ans[i] + '0';
        }
        return s;
    }
};