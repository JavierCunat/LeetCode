class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1, n2 = num2.size()-1;
        int carry = 0;
        string res;
        res.reserve(max(num1.size(), num2.size()) + 1);

        //add nums and put into string with a carry
        while(n1 >= 0 || n2 >= 0 || carry) {
            int d1 = (n1 >= 0 ? num1[n1] - '0' : 0);
            int d2 = (n2 >= 0 ? num2[n2] - '0' : 0);
            int sum = d1 + d2 + carry;

            res.push_back(char('0' + (sum % 10)));
            carry = sum / 10;

            n1--; n2--;
        }

        //reverse
        int l = 0, r = res.size()-1;
        while(l < r) {
            swap(res[l++], res[r--]);
        }

        return res;
    }
};