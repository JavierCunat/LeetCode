class Solution {
public:
    string decodeString(string s) {
        //reviewed 1/18/2026
        stack<int> count;
        stack<string> strings;
        string currString = "";
        int currNum = 0;

        for(char c : s) {
            if(isdigit(c)) {
                //build the number handles multi-digit cases like 12[abc]
                currNum = currNum * 10 + (c - '0');
            } else if(c == '[') {
                count.push(currNum);
                strings.push(currString);
                currNum = 0;
                currString = "";
            } else if(c == ']') {
                int repeatCount = count.top(); count.pop();
                string temp = strings.top(); strings.pop();
                while(repeatCount--) temp += currString;
                currString = temp;
            } else {
                currString += c;
            }
        }

        return currString;
    }
};
