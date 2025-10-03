class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i = 0; i < n1; i++) L[i] = nums[left + i];
        for(int i = 0; i < n2; i++) R[i] = nums[mid + i + 1];

        int i = 0, j = 0;
        int k = left;

        while(i < n1 && j < n2) {
            if(L[i] > R[j]) {
                nums[k] = R[j++];
            } else {
                nums[k] = L[i++];
            }
            k++;
        }

        while(i < n1) {
            nums[k] = L[i++];
            k++;
        }

        while(j < n2) {
            nums[k] = R[j++];
            k++;
        }

        
    }

    void sortArray(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right - left) / 2; //avoid overflow

        sortArray(nums, left, mid);
        sortArray(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;

        sortArray(nums, left, right);
        return nums;
    }
};