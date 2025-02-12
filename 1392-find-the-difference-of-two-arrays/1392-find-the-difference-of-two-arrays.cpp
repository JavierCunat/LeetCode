class Solution {
public:

    vector<int> getElemsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int> onlyInNums1;
       unordered_set<int> existsInNum2;
        //have a midterm today so for my daily code I'll review this problem that I did a long time ago
        //sometimes I look at these solutions and like wow this was neat!
        //instead of making a function like this we can put both in sets and then remove the indistinct ones I think

       for(int num : nums2) {
        existsInNum2.insert(num);
       }

       for(int num : nums1) {
        //if not in num2 we add to only in nums1
        if(existsInNum2.find(num) == existsInNum2.end()) {
            onlyInNums1.insert(num);
        }
       }

       return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      return { getElemsOnlyInFirstList(nums1, nums2), getElemsOnlyInFirstList(nums2, nums1) };
    }


};
