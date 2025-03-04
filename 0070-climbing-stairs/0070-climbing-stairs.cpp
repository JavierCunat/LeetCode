class Solution {
public:
    //review 3/3/2025
    int climbStairs(int n) {
        map<int,int> memo = { {0, 0}, {1,1}, {2,2}, {3,3} }; 
        return climbStairsHelper(n, memo);
    }

    int climbStairsHelper(int n, map<int,int>& memo) {
        if(memo.count(n) > 0) {
            return memo[n];
        } else{
            int result = climbStairsHelper(n-1, memo) + climbStairsHelper(n-2, memo);
            memo[n] = result;
            return result;
        }
    }
};
