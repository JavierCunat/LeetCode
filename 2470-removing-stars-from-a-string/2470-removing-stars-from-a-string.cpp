class Solution {
public:
    string removeStars(string s) {
        //reviewed on 3/15/2025
        //personally think two pointers would be easier stack topic threw me off
        //use reverse to not exceed time limit, when I first tried I did s = s+stack.pop which is n^2
        string res = "";
        int size = s.size();
        stack<char> stack;
        for(char c : s) {
            if(!stack.empty() && c == '*') stack.pop();
            else stack.push(c);
        }

        while(!stack.empty()) {
            res+=stack.top();
            stack.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
