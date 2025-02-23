class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int t[n];
        function<int(int, int)> mergeSort = [&](int l, int r) -> int {
            if (l >= r) {
                return 0;
            }
            int mid = (l + r) >> 1;
            int ans = mergeSort(l, mid) + mergeSort(mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j] * 2LL) {
                    ++i;
                } else {
                    ans += mid - i + 1;
                    ++j;
                }
            }
            i = l;
            j = mid + 1;
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    t[k++] = nums[i++];
                } else {
                    t[k++] = nums[j++];
                }
            }
            while (i <= mid) {
                t[k++] = nums[i++];
            }
            while (j <= r) {
                t[k++] = nums[j++];
            }
            for (i = l; i <= r; ++i) {
                nums[i] = t[i - l];
            }
            return ans;
        };
        return mergeSort(0, n - 1);
    }
};