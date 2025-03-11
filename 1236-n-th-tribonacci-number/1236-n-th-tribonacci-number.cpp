class Solution {
public:
    int tribonacci(int n) {
        //dp should be able to do this typically recursive problem iteratively
        vector<int> res = {0, 1, 1};

        int resSize = res.size();
        while(resSize < n+1) {
            int toadd = res[resSize-1] + res[resSize-2] + res[resSize-3];
            res.push_back(toadd);
            resSize++;
        }

        return res[n];

    }
};