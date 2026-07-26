class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int n = nums.size();
        int longest = INT_MIN;
        int seclongest = INT_MIN;
        int thirdlongest = INT_MIN;
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for(int i =0 ; i<n ; i++){
            if(nums[i]>longest){
            thirdlongest = seclongest;
            seclongest = longest;
            longest = nums[i];
            }else if(nums[i]> seclongest ){
               thirdlongest = seclongest;
               seclongest = nums[i];

            }else if(nums[i]>thirdlongest){
                thirdlongest = nums[i];
            }

            if(nums[i]<mini1){
                mini2 = mini1;
                mini1 = nums[i];
            }else if(nums[i]<mini2){
                mini2 = nums[i];
            }
        }
// long long opt1 = (long long)longest* seclongest*thirdlongest;
long long opt1 = 1LL * longest * seclongest * thirdlongest;

long long opt2 = (long long)longest* mini1* mini2;


return max(opt1, opt2);
        
    }
};