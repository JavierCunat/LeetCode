class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;

        long long N = n;

        if(N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        double base = x;
        double res = 1.0;

        //fast exponentiation O(nlogn)
        while(N > 0) {
            if(N & 1) res*=base;
            base *= base;
            N >>= 1;
        }

        return res;
    }
};