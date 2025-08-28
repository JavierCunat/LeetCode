class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size <= 1) return 0;

        //sort intervals by time ascending
        sort(intervals.begin(), intervals.end(), //comparator lambda
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            }
        );

        int prevEnd = intervals[0][1];
        int removes = 0;

        for(int i = 1; i < size; i++) {
            if(intervals[i][0] < prevEnd) {
                removes++;
            } else {
                prevEnd = intervals[i][1];
            }        
        }
      

        return removes;
    }
};