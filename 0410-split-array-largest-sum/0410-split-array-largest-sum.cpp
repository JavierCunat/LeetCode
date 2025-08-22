class Solution {
public:

    bool isMoreSplitable(vector<int>& nums, int k, int max) {
        int sum = 0;
        int splits = 1;

        for(int num: nums) {
            if(sum + num > max) {
                splits++;
                sum = 0;
            }
            sum+=num;
        }

        return splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        //binary search + greedy approach
        int low = *max_element(nums.begin(), nums.end()); //biggest num
        int high = accumulate(nums.begin(), nums.end(), 0); //sum

        while(low < high) {
            int mid = (high + low) / 2;
            if(isMoreSplitable(nums, k, mid)) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};