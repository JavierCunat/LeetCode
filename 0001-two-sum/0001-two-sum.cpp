class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map of index to complement of target
        unordered_map<int, int> map;
        vector<int> res;
        int size = nums.size();

        //fill map
        for(size_t i = 0; i < size; i++) {
            map[target-nums[i]] = i;
        }

        for(size_t i = 0; i < size; i++) {
            if( (map.count(nums[i]) > 0) && i != map[nums[i]]){
                res.push_back(map[nums[i]]);
                res.push_back(i);
                break;
            }
        }

        return res;


    }

};