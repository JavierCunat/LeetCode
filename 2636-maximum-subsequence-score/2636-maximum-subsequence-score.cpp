class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums2.size();

       //sort indicies based on nums2 in descending order "sort based on value of nums2"
       //since matching pairs I guess thats how we keep the indexes relevant even though we sorted and lose them
       vector<pair<int,int>> pairs;
       for(int i = 0; i < size; i++) {
        pairs.emplace_back(nums2[i], nums1[i]); //like push_back but more efficient with pairs
        //like pushback({nums2[i], nums1[i]})
       }
       sort(pairs.rbegin(), pairs.rend()); //reverse iterators

      //priority queue to store k largest elements in nums1, greater cmp achieves min-heap behavior
      priority_queue<int, vector<int>, greater<int>> pq; //even though pqs are always vectors under the hood the third param has to be a cmp function
      long long maxScore = 0, sum = 0;

      //iterate through sorted pairs
      //the min-heap helps us remove the smallest number when the heap exceeds size k
      for(int i = 0; i < size; i++) {
        int minNum2 = pairs[i].first;
        int num1 = pairs[i].second;

        pq.push(num1);
        sum += num1;

        if(pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        //update max score when we are at a min heap of k elements
        if(pq.size() == k) {
            maxScore = max(maxScore, sum * minNum2);
        }
      }

        return maxScore;
    }
};