class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res; 
        sort(intervals.begin(), intervals.end(), compare);

        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            auto& curr = res.back();
            auto& next = intervals[i];

            if(curr[1] >= next[0]) {
                curr[1] = max(curr[1], next[1]);
            } else {
                res.push_back(next);
            }
        }

        return res;
    }
};