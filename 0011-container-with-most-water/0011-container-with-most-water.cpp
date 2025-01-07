class Solution {
public:
    int maxArea(vector<int>& height) {
        //brute force with two pointers
        int i = 0, j = height.size()-1;
        int distance = j-i;
        int resArea = INT_MIN;

        while(i < j) {
            int maxHeight = min(height[i], height[j]);
            int area = maxHeight * distance;
            if(area > resArea) {
                resArea = maxHeight*distance;
            }

            (height[i] >= height[j]) ? j-- : i++; //move the smaller height bar and keep the largest

            distance = j-i;
        }

        return resArea;
    }
};