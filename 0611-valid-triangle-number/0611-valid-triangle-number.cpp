class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //valid triangles means add two sides and greater than the 3rd
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int triangles = 0;
        
        for(int k = n - 1; k >= 2; k--) {
            int i = 0, j = k -1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    triangles += (j - i); //since sorted all these combinations are valid triangles
                    j--;
                } else {
                    i++;
                }
            }
        }

        return triangles;
    }
};