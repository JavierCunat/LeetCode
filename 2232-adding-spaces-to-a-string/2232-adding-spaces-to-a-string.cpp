class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //Reviewed on 3/14/2025
        string res = "";
        vector<string> strings;
        int j = 0;
        int index = 0;

        //put all words in a vec based on spaces ints
        for(int i = 0; i < s.size(); i++) {
            if(j < spaces.size() && i == spaces[j]) {
                strings.push_back(s.substr(index, i - index));
                index = i;
                j++;
            }
        }

        //doesn't get the last word in the vec so brute for this lmao
        strings.push_back(s.substr(index));

        //construct the result string
        for(int i = 0; i < strings.size(); i++) {
            if(i == strings.size()-1) {
                res.append(strings[i]);
            } else {
                res.append(strings[i] + " ");
            }
        }

        return res;
    }
};
