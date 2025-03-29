class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long> freq;
        long count = 0;

        for (int num : nums) {
            int key = num - rev(num);
            count = (count + freq[key]) % MOD;
            freq[key]++;
        }

        return count;
    }
};