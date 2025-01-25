class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> res(n+1);
       //dp approach we use the previous elements of the array and right shift and then add 1
       for(size_t i = 0; i <= n; i++) {
        res[i] = res[i>>1] + (i & 1);
       }
       return res;
    }
};