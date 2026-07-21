class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum =0 , curr_sum1 =0, maxsum = INT_MIN, minsum = INT_MAX;
int curr_sum2 =0;
        for(auto i: nums){
            totalsum += i;
            curr_sum1+=i;
            curr_sum2 +=i;
            maxsum = max(maxsum ,curr_sum1 );

            if(curr_sum1 <0){
                curr_sum1 = 0;
            }
            minsum = min(minsum , curr_sum2);
            if(curr_sum2 >0){
                curr_sum2 =0;
            }
        }
            if(totalsum == minsum){
                return maxsum;
            }

            return max(maxsum , totalsum - minsum);
        
        
    }
};