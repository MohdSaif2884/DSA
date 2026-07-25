 class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        long long minsum = nums[0];
        long long maxsum = nums[0];
        long long ans = abs(1LL * nums[0]);

        for (int i = 1; i < n; i++) {

            minsum = min(minsum + nums[i], 1LL * nums[i]);
            maxsum = max(maxsum + nums[i], 1LL * nums[i]);

            ans = max(ans, max(maxsum, abs(minsum)));
        }

        return (int)ans;
    }
};