class Solution {
public:
    int minAddToMakeValid(string s) {
        // )))
        int removes = 0;
        stack<char> stack;

        for(char c : s) {
            if(c == '(') {
                stack.push(c);
            } else if(!stack.empty()) {
                stack.pop();
            } else {
                removes++;
            }
        }

        return removes + stack.size();
    }
};