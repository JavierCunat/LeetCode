class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, sum = 0;
        int leftMax = height[left], rightMax = height[right];

        while(left < right) {
            if(leftMax <= rightMax) {
                sum += max(0, leftMax - height[left]);
                left++;
                leftMax = max(leftMax, height[left]);
            } else {
                sum += max(0, rightMax - height[right]);
                right--;
                rightMax = max(rightMax, height[right]);
            }
        }

        return sum;
    }
};