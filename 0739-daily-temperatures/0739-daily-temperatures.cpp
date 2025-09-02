class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answers(n, 0);
        stack<int> s;

        for(int i = 0; i < n; i++) {
    ;
            while(!s.empty() && temperatures[i] > temperatures[s.top()] ){
                int prev = s.top(); s.pop();
                answers[prev] = i - prev; // distance to the next warmer day
            }
            
            s.push(i);
        }

        return answers;
    }
};