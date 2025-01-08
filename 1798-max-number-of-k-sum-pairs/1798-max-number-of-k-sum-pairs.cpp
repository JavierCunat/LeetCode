class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //first try O(n log n) intuitive approach with sorting and two pointers beats 41%
        //optimize by using an unordered map and iterating through each elem in nums, store each complement with the amount of times it has appeared. If the complement is in the map add to res and remove else add the regular num
        unordered_map<int,int> map;
        int res = 0;

        for(int num : nums) {
            int complement = k - num;
            if(map[complement] > 0) {
                res++;
                map[complement]--;
            } else {
                map[num]++;
            }
        }

        return res;
    }
};