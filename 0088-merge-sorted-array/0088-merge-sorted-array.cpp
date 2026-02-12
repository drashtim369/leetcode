class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int numOfZeroes = (nums1.size() > nums2.size()) ? nums1.size() - nums2.size() : nums2.size() - nums1.size();
    for (int i = numOfZeroes; i < nums1.size(); i++) { 
        nums1[i] = nums2[i-numOfZeroes];
    }
    sort(nums1.begin(), nums1.end());
    }
};