class Solution {
public:

    //reviewed on 3/7/3035
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> map;
        vector<string> res;
        int j = 0;
        for(string name : names) {
            map[heights[j]] = name;
            j++;
        }

        //lamda function same thing as passing comp as third argument
        sort(heights.begin(), heights.end(), [](int a, int b)  {
            return a > b;
        });

        for(int height : heights) {
            res.push_back(map[height]);
        }

        return res;

        //looking back can actually use a priority queue
    }
};
