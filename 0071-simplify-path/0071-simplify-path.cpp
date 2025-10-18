class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        vector<string> res;
        for(int i = 0; i <= path.size(); i++) {
            if(i == path.size() || path[i] == '/') {
                if(!token.empty()) {
                    if(token == ".") {} //ignore
                    else if(token == "..") {
                        if(!res.empty()) res.pop_back(); 
                    }
                    else { res.push_back(token); }
                }
                token.clear();
            } else {
                token.push_back(path[i]);
            }
        }

        if (res.empty()) return "/";

        string clean;
        for (const string& w : res) clean += "/" + w;
        return clean;
    }
};