class Solution {
public:

    vector<vector<int>> genHelp(int numRows, vector<vector<int>>& res, int curr) {
        if(curr == numRows) {
            return res;
        }

        vector<int> row; //[1]
        row.push_back(1);

        if(curr > 0) {
            vector<int>& prev = res[curr - 1]; // Reference to the previous row
            for(int j = 1; j < prev.size(); j++) {
                row.push_back(prev[j-1] + prev[j]);
            }
            row.push_back(1);
        }

        res.push_back(row);
        return genHelp(numRows, res, curr + 1);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        return genHelp(numRows, res, 0);
    }
};