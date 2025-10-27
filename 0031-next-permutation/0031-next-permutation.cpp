class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size()-2, r = nums.size()-1;
        //find the first rise in the array moving from the back of it
        //if first rise is at index 0 just sort the array
        //else we swap the first rise index with the smallest number greater than it after it
        //then reverse everything after i

        int idx = -1;
        while(l >= 0) {
            if(nums[l] < nums[r]) {
                idx = l;
                break;
            } else {
                r--;
                l--;
            }
        }

        //sort is ascending or reverse it same thing
        if(idx == -1) { reverse(nums.begin(), nums.end()); return; }

        //find smallest number to the right
        int j = nums.size()-1;
        while(nums[j] <= nums[idx]) j--;

        //swap smallest rising number with smallest after this rising but bigger than it
        swap(nums[idx], nums[j]);

        //reverse rest of arr after idx
        int k = nums.size()-1;
        idx++;
        while(idx < k) {
            swap(nums[idx++], nums[k--]);
        }


    }
};