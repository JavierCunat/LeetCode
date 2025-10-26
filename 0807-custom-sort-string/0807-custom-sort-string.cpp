class Solution {
public:
    string customSortString(string order, string s) {
        ///bucket approach
        //vector with pair char to times it occurs
        //['c': 2, 'b': 1, somelast bucket with all the not in order] 
        vector<pair<char, int>> v;
        vector<char> notFound;
        unordered_map<char, int> m;

        for(int i = 0; i < order.size(); i++) {
            v.push_back({order[i], 0});
            m[order[i]] = i;
        }

        for(int i = 0; i < s.size(); i++) {
            auto it = m.find(s[i]);
            if(it != m.end()) {
                v[it->second].second++;
            } else {
                notFound.push_back(s[i]);
            }
        }

        string res = "";
        for(int i = 0; i < v.size(); i++) {
            int times = v[i].second;
            for(int j = 0; j < times; j++) {
                res+=v[i].first;
            }
        }

        for(char c : notFound) {
            res+=c;
        }

        return res;
    }
};