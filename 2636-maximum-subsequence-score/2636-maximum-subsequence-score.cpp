class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums2.size();

       //sort indicies based on nums2 in descending order "sort based on value of nums2"
       //since matching pairs I guess thats how we keep the indexes relevant even though we sorted and lose them
       vector<pair<int,int>> pairs;
       for(int i = 0; i < size; i++) {
        pairs.emplace_back(nums2[i], nums1[i]);
       }
       sort(pairs.rbegin(), pairs.rend());

      //priority queue to store k largest elements in nums1
      priority_queue<int, vector<int>, greater<int>> pq;
      long long maxScore = 0, sum = 0;

      //iterate through sorted pairs
      for(int i = 0; i < size; i++) {
        int minNum2 = pairs[i].first;
        int num1 = pairs[i].second;

        pq.push(num1);
        sum += num1;

        if(pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        if(pq.size() == k) {
            maxScore = max(maxScore, sum * minNum2);
        }
      }

        return maxScore;
    }
};