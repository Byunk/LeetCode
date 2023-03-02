class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void merge(vector<int>& A, int low, int mid, int high) {
        vector<int> sorted;

        int l = low, r = mid + 1;
        while (l <= mid && r <= high) {
            if (A[l] <= A[r]) {
                sorted.push_back(A[l++]);
            } else {
                sorted.push_back(A[r++]);
            }
        }
        while (l <= mid) {
            sorted.push_back(A[l++]);
        }
        while (r <= high) {
            sorted.push_back(A[r++]);
        }
        
        for (int i = low; i <= high; i++) {
            A[i] = sorted[i - low];
        }
    }

    void mergeSort(vector<int>& A, int low, int high) {
        if (low >= high) {
            return;
        }
        
        // divide
        int mid = (low + high) / 2;

        // conquer
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
};