class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int biggest = arr[size-1];
        int pointer = 0;
        vector<int> missing;

        for(int i = 1; i <= biggest && missing.size() < k; i++) {
            if(pointer < size && arr[pointer] == i) {
                pointer++;
            } else {
                missing.push_back(i);
            }
        }
        
        if(missing.size() >= k) return missing[k-1];

        return biggest + (k - missing.size());
    }
};