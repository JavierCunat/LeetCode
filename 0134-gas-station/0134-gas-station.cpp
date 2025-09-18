class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        
        int tank = 0, start = 0, total = 0;

        for(int i = 0; i < size; i++) {
            tank += gas[i] - cost[i];
            total +=  gas[i] - cost[i];
            if(tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }

        return (total >= 0 ? start : -1);
    }
};