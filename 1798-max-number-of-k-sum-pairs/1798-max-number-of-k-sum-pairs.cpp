class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //first try O(n log n) intuitive approach with sorting and two pointers
        int i = 0, res = 0, j = nums.size()-1;
        sort(nums.begin(), nums.end());

        while(i < j) {
            if(nums[i] + nums[j] == k) {
                res++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] < k){
                i++;
            } else {
                j--;
            }
        }

        return res;
    }
};