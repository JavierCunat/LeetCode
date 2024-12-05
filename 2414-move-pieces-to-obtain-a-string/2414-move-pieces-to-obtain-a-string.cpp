class Solution {
public:
    bool canChange(string start, string target) {
        if(start == target) { return true; }
        int indexL = 0;
        int indexR = 0;

        for(int i = 0; i < start.size(); i++) {
            int cur = start[i];
            int goal = target[i];

            if(cur == 'R') {
                if(indexL > 0) {
                    return false;
                }
                indexR++;
            }
            if(goal == 'R') {
                if(indexR == 0) {
                    return false;
                }
                indexR--;
            }
            if(goal == 'L') {
                if(indexR > 0) {
                    return false;
                }
                indexL++;
            }
            
            if(cur == 'L') {
                if(indexL == 0) {
                    return false;
                }
                indexL--;
            }
        }
        return indexL == 0 && indexR == 0;
    }
};