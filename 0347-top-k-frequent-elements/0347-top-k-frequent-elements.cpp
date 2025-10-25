class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store freq map of num to number of occurences
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        //comparator
        auto by_second =[](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };

        //if want to specify pq operator need to also declare underlying structure as second param
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(by_second)> pq(by_second);

        //push freq map into pq
        for(auto& kv : freq) {
            pq.push({kv.first, kv.second});
        }

        //pop the first k vals from pq and store in res list
        vector<int> res;
        for(int i = 0; i < k; i++) {
            auto& kv = pq.top();
            res.push_back(kv.first); pq.pop();
        }

        return res;
    }
};