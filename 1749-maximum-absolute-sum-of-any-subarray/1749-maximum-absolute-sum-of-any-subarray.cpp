class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
int n = nums.size();
        long long minsum =nums[0];
        long long maxsum =nums[0];
    //    int maxi = nums[0];
      long long maxi = abs(1LL * nums[0]);
        for(int i =1 ;i <n ; i++){
            minsum = min(minsum + nums[i],(long long)nums[i] );
            maxsum = max(maxsum + nums[i],(long long) nums[i]);
            maxi = max(maxi , max(maxsum , abs(minsum)));
            
        }
        return (int) maxi;
        
    }
};