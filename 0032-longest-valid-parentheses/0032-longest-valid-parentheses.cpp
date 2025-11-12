class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack; //instead of storing chars store last bad right parenthesis
        stack.push(-1); //the right answer will be i - stack.top() keep this as the running max

        //brute force just start at index i go all way until a invalid arrangment that is your longest so far then keep max and try i + 1 and so on O(n^2)

        int maxSeen = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();

                if(stack.empty()) {
                    stack.push(i);
                } else {
                    maxSeen = max(maxSeen, i - stack.top());
                }
            }
            
        }

        return maxSeen;

    }
};