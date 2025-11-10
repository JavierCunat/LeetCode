class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> results;
        //recipe[i] -> ingredients[i][[]]-> check supplies
        //how do we handle when ingredient has a recipe, keep set of made recipes -> would work but not if recipes in different orders instead use Khans algo

        unordered_map<string, vector<string>> needed; //ingredient -> recipes that need it
        unordered_map<string, int> inDegrees; //recipe -> # of needed items

        for(int i = 0; i < recipes.size(); i++) {
            for(string ingredient : ingredients[i]) {
                needed[ingredient].push_back(recipes[i]);
                inDegrees[recipes[i]]++;
            }
        }

        queue<string> q;
        for(const string& s : supplies) q.push(s);

        vector<string> res;

        while(!q.empty()) {
            string have = q.front(); q.pop();
            
            if(!needed.count(have)) continue; //this item isn;t needed

            for(const string& r : needed[have]) {
                if(--inDegrees[r] == 0) {
                    res.push_back(r);
                    q.push(r); //crafted recipe is avaliable like a supply
                }
            }
            
        }


        return res;
    }
};