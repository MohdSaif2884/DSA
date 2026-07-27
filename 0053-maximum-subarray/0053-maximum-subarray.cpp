class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = -1e8;
        int sum =-1e8;

        for(int i = 0; i<nums.size(); i++){
            sum = max(nums[i], sum + nums[i]);
            maxi = max(maxi , sum);
        }
        // return maxi;
        if(maxi == -1e8){
            return -1;
        }

        return maxi;
        
    }
};