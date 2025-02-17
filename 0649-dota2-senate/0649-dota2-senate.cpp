class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiants, dires;
        size_t size = senate.size();

        //store the indexes in the queues
        for(size_t i = 0; i < size; i++) {
            if(senate[i] == 'R') radiants.push(i);
            else dires.push(i);
        }

        while(!radiants.empty() && !dires.empty()) {
            int r = radiants.front();
            int d = dires.front();

            radiants.pop();
            dires.pop();

            //the smaller index wins because its ahead
            if(r < d) {
                radiants.push(r + size);
            } else {
                dires.push(d + size);
            }
        }

        return (dires.empty()) ? "Radiant" : "Dire";
        
    }
};