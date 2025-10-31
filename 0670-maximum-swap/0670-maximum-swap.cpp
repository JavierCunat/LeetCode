class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        //for the first digit on left where thers a larger digit on right swap
        //98368
        vector<int> v(10, -1);
        for(int i = 0; i < n.length(); i++) {
            v[n[i]-'0'] = i;
        }

        for(int i = 0; i < n.length(); i++) {
            int curr = n[i] - '0';

            for(int j = 9; j > curr; j--) {
                if(v[j] > i) {
                    swap(n[i], n[v[j]]);
                    return stoi(n);
                }
            }

        }


        return num;
    }
};