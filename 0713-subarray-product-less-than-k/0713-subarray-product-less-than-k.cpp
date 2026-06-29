class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        int prd =1;
        if(k <=1){
            return 0;
        }
int j =0;
        for(int i =0 ; i<n ; i++){
            prd*= nums[i];

            while(prd >=k){
                prd/=nums[j];
                j++;
            }
            cnt += (i -j+1);
            
        }
        return cnt;
    }
};