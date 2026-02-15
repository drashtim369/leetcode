class Solution {
public:
    int mergeArrays(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int cnt = 0;
        int left  = low;       // start of left half
        int right = mid + 1;   // start of right half
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > arr[right] * 2) {
                right++;
            }
            cnt += right - (mid + 1);
        }
        right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        
        for (int i = 0; i < temp.size(); i++) {
            arr[low + i] = temp[i];
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += mergeArrays(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int res = mergeSort(nums,0,n-1);
        return res;
    }
};