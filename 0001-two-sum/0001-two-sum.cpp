class Solution {
//reviewed 10/30/2025
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map of index to complement of target
        unordered_map<int, int> map;
        int size = nums.size();

        //fill map with array elems and try to find complement of curr elem
        for(int i = 0; i < size; i++) {
            int complement = target - nums[i];
            if(map.count(complement) > 0) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }

        return {};


    }

};
