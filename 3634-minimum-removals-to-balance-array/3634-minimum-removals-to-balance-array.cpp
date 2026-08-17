class Solution {
private:
    int fun(vector<int>& nums, int k, int idx) {
        int lo = idx, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if ((1LL*k * nums[idx]) < 1LL*nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }

public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int idx = fun(nums, k, i);
            ans = min(ans, n - 1 - idx + i);
        }
        return ans;
    }
};