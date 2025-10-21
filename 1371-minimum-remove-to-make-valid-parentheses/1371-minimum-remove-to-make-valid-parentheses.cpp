class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        stack<char> stack;

        //forward pass
        for(char c : s) {
            if(c == '(') {
                stack.push(c);
                res.push_back(c);
            } else if(c == ')') {
                if(!stack.empty()) {
                    res.push_back(c);
                    stack.pop();
                }
            } else {
                res.push_back(c);
            }
        }

        string res2 = "";
        //backward pass [has to be backward can't do another forward consider  a(b)c)( ]
        int size = res.size();
        for(int i = size-1; i >= 0; i--) {
            if(res[i] == '(' && !stack.empty()) {
                stack.pop();
            } else {
                res2.push_back(res[i]);
            }
        }

        reverse(res2.begin(), res2.end());


        return res2;
    }
};