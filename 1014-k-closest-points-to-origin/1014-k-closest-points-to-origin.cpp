class Solution {
public:

    static long long dist(const vector<int>& v) {
        return 1LL * v[0] * v[0] + 1LL * v[1] * v[1]; 
    }

    static bool byDist(const vector<int>& a, const vector<int>& b) {
        long long ad = dist(a), bd = dist(b);
        if(ad != bd) return ad < bd;
        return a < b;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), byDist);
        if (k > (int)points.size()) k = (int)points.size();
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};