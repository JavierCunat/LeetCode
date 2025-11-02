class Solution {

private:
    struct LogEvent {
        int id;
        bool action;
        int timestamp;
    };

    inline LogEvent parseLog(string& str) {
        int p1 = str.find(':');
        int p2 = str.find(':', p1 + 1);

        int id = stoi(str.substr(0, p1));
        string action = str.substr(p1 + 1, p2 - (p1 + 1)); //startIndex + how far you want to go not like [0:2]
        int timestamp = stoi(str.substr(p2 + 1));

        return {id, action == "start", timestamp};
    }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<int> s;
        int size = logs.size();
        int prevTime = 0;

        for(int i = 0; i < size; i++) {
            string log = logs[i];

            LogEvent l = parseLog(log);

            if(l.action) {
                //if start add id to stack and if stack isn't empty times[popd ID] += new startTime - prevTime
                //reset prevTime = startTime
                if(!s.empty()) {
                    times[s.top()] += l.timestamp - prevTime;
                }

                s.push(l.id);
                prevTime = l.timestamp;
            } else {
                //if end pop from stack and add to times[popd ID] += endTime - prevTime + 1
                //reset prevTime = endTime + 1
                int id = s.top(); s.pop();
                times[id] += l.timestamp - prevTime + 1;
                prevTime = l.timestamp +  1;
            }
            
        }

        return times;
    }
};