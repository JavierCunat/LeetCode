class Solution {
public:
    string reverseWords(string s) {
        //brute force af..
        string res = "";
        int size = s.size();
        stack<string> words;
        string word = "";
    
        for(int i = 0; i < size; i++) {
            if(i != size-1 && s[i] == ' ' && !word.empty()) {
                words.push(word);
                word = "";
            }
            else if(s[i] != ' ') {
                word+=s[i];
            }
        }

        if(!word.empty()) {
            words.push(word);
        }

        int sSize= words.size();
        for(int i = 0; i < sSize; i++) {
            res += words.top();
            words.pop();
            if(i != sSize-1) { res += " "; }
        }
        
        return res;
    }
};