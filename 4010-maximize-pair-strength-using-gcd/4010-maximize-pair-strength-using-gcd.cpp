class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();

        long long maxi = LONG_MIN;

        for(int i =0 ; i<n ; i++){
            for(int j = i+1; j <n ; j++){
              long long  t =  (long long)nums[i] * nums[j];
               long long crntgcd =  gcd(nums[i], nums[j]) ;
long long temp = t /(crntgcd * crntgcd);
              maxi = max(temp, maxi);
              
            }
        }

        return maxi;
    }
};