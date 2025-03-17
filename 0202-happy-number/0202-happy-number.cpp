class Solution {
public:
//reviewed on 3/16/2025
    bool isHappy(int n) {
        unordered_set<int> set;
        
        while(n!= 1 && !set.count(n)) {
            set.insert(n);
            int sum = 0;

            while(n > 0) {
                int s = n % 10;
                sum+=s*s;
                n/=10;
            }

            n = sum;
        }

        return n==1;
    }
};
