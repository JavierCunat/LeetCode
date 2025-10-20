class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        return quickSelect(nums, 0, n-1, target);
    }

private:
    int partition(vector<int>& A, int left, int right, int pivot) {
        int pivotVal = A[pivot];
        swap(A[pivot], A[right]);
        int store = left;
        for(int i = left; i < right; i++) {
            if(A[i] < pivotVal) {
                swap(A[store++], A[i]);
            }
        }
        swap(A[store], A[right]);
        return store;
    }

    int quickSelect(vector<int>& A, int left, int right, int k) {
        if(left == right) {
            return A[left];
        }

        int pivot = left + (right - left) / 2;

        int pivotIdx = partition(A, left, right, pivot);

        if(pivotIdx == k) {
            return A[pivotIdx];
        } else if(pivotIdx > k) {
            return quickSelect(A, left, pivotIdx - 1, k);
        } else {
            return quickSelect(A, pivotIdx + 1, right, k);
        }
    }

};