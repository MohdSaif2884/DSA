 class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long sum = 0;
        for (int x : nums)
            sum += x;

        int k = sum % p;

        if (k == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long pref = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            pref += nums[i];

            int curr = pref % p;
            int target = (curr - k + p) % p;

            if (mp.count(target))
                ans = min(ans, i - mp[target]);

            mp[curr] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};