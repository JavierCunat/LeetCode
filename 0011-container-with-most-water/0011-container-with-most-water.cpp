class Solution {
public:
//reviewed on 3/16/2025
    int maxArea(vector<int>& height) {
        //brute force with two pointers beats 100% :)
        //optimized space complexity by removing redundance distsance var and also use max() method
        int i = 0, j = height.size()-1;
        int resArea = INT_MIN;

        while(i < j) {
            int curArea = min(height[i], height[j]) * (j-i);
            resArea = max(resArea, curArea);
          
            (height[i] >= height[j]) ? j-- : i++; //move the pointer pointing to the smaller height
        }

        return resArea;
    }
};
