class Solution {
public:
    //106b intutiion choose explore unchoose
    void letterCombinations(vector<string> &res, string &digits, map<char, string> &map, string soFar, size_t size, size_t index) {
        //base case
        if(soFar.size() == size) {
            res.push_back(soFar);
            return;
        }
        
        for(char c : map[digits[index]]) {
            //choose with index, explore those options by calling recursive case, then uchoose by doing index+1
            letterCombinations(res, digits, map, soFar + c, size, index + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        size_t size = digits.size();
        letterCombinations(res, digits, map, "", size, 0);
        return res;
    }

};