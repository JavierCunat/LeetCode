class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //brute force O(n^2)
       int size = nums.size();

       for(int i = 0; i < size; i++) {
        int left = 0;
        int right = i+1;
        int lhs = 0, rhs = 0;

        while(left < i && right < size) {
            lhs+=nums[left++];
            rhs+=nums[right++];
        }

        while(left < i) {
            lhs+=nums[left++];
        }

        while(right < size) {
            rhs+=nums[right++];
        }

        if(lhs == rhs) {
            return i;
        } 
        
       }

       return -1;
    }
};