class Solution {

public:
    int calculate(string s) {
        int len = s.length();
        if(len == 0) return 0;
        stack<int> stack;
        char op = '+';
        int currNum = 0;

        for(int i = 0; i < len; i++) {
            char currChar = s[i];
            if(isdigit(currChar)) {
                currNum = (currNum * 10) + (currChar - '0'); //handle numbers with more than one digit
            }
            if(!isdigit(currChar) && !iswspace(currChar) || i == len-1) {
                //keep track of previous operatior
                if(op == '-') {
                    stack.push(-currNum);
                } else if(op == '+') {
                    stack.push(currNum);
                } else if(op == '*') {
                    int prev = stack.top(); stack.pop();
                    stack.push(prev * currNum);
                } else if(op == '/') {
                    int prev = stack.top(); stack.pop();
                    stack.push(prev / currNum);
                }
                op = currChar;
                currNum = 0;
            }
        }

        int res = 0;
        while(!stack.empty()) {
            res += stack.top(); stack.pop();
        }
        return res;
    }
};