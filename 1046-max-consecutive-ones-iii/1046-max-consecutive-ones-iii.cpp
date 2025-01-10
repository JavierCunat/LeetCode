class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size(), j = 0, zeros = 0, maxSeen = 0;

        for(int i = 0; i < size; i++) {

           if(nums[i] == 0) {
                zeros++;
           }

            //shrink window if zeros exceeds k
           while(zeros > k) {
            if(nums[j] == 0) {
                zeros--;
            }
            j++;
           }
            
            maxSeen = max(maxSeen, i - j + 1);
        }

        return maxSeen;
    }
};