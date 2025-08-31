class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        
        sort(points.begin(), points.end(),
            [](vector<int>& a, vector<int>& b) {
                return(a[1] < b[1]);
            }
        );

        int prevEnd = points[0][1];
        int darts = 1;

        for(int i = 0; i < size; i++) {
            if(points[i][0] > prevEnd) {
                darts++;
                prevEnd = points[i][1];
            }
        }

        return darts;
    }
};