class Solution {
public:

    //Reviewed on 3/15/2025
    int fibHelper(int n, unordered_map<int,int>& map) {
        if(map.count(n)) {
            return map[n];
        } else {
            int result = fibHelper(n-1, map) + fibHelper(n-2, map);
            map[n] = result;
            return result;
        }
    }

    int fib(int n) {
        unordered_map<int, int> map = { {0,0}, {1,1}, {2,1}, {3,2} };
        return fibHelper(n, map);
    }
};
