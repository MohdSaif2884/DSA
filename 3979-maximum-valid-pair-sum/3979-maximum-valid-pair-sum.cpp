class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>suff(n+1);
        for(int i = n -1; i >=0 ; i--){
            suff[i] = max(nums[i], suff[i+1]);
        }

        int ans =0;

        for(int i = 0 ; i +k <n ; i++){
            ans = max(ans,nums[i] + suff[i+k]);
        }
        return ans;
        
    }
};