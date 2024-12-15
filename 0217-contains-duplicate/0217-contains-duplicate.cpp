class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) {
            return false; //short circuit
        }

        unordered_set<int> seen;
        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            } else {
                seen.insert(num);
            }
        }
        return false;
    }
};