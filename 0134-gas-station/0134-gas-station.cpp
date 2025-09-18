class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        vector<int> diffs(size, 0);
        vector<int> toTry;

        for(int i = 0; i < size; i++) {
            diffs[i] = gas[i] - cost[i];
            if(diffs[i] > 0) {
                toTry.push_back(i);
            }
        }

        // [-2, -2, -2, 3, 3]

        int sum = accumulate(diffs.begin(), diffs.end(), 0);

        if(sum < 0) return -1;
        if(sum >= 0 && toTry.empty()) return 0;

        for(int index : toTry) {
            sum = 0;
            for(int i = 0; i < size; i++) {
                sum += gas[(index + i) % size] - cost[(index + i) % size];
                if(sum < 0) break;
            }
            if(sum >= 0) return index;
        }

        return -1;
    }
};