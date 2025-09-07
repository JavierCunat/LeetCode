class Solution {
public:
    void combinationSum3(int &k, int &n, vector<vector<int>> &res, int currSum, vector<int> &currArr, int index) {
        //reviewed 09/06/2025
        if(currArr.size() == k) {
            if(currSum == n) {
                res.push_back(currArr);
            } 
            return;
        }

        for(int i = index; i < 10; i++) {
            if (i > n) break;  //optimization stop early if 'i' exceeds remaining sum
            currArr.push_back(i); //choose
            combinationSum3(k, n, res, currSum + i, currArr, i + 1); //explore
            currArr.pop_back(); //unchoose
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> currArr;
        combinationSum3(k, n, res, 0, currArr, 1);
        return res;
    }
};
