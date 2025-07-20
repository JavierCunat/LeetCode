class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal+1, 0);
        for(int num: nums) {
            points[num]+=num;
        }

        int skip = 0, take = 0;
        for(int val: points) {
            int temp = take;
            take = val + skip;
            skip = max(skip, temp);
        }
        return max(skip, take);

    }
};