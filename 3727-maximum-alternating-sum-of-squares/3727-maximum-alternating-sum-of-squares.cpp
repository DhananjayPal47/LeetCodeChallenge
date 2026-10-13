class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& num : nums) {
            num = abs(num);
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mid = n / 2;
        long long score = 0;

        for (int i = 0; i < n; i++) {
            long long square = 1LL * nums[i] * nums[i];

            if (i < mid) {
                score -= square;
            } else {
                score += square;
            }
        }

        return score;
    }
};