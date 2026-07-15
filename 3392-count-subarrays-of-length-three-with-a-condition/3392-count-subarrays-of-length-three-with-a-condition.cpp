class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        int n = nums.size();

        int cnt =0;
        for (int crnt =1 ; crnt <n-1 ; crnt++){

            int prev = crnt-1;
            int next = crnt+1;

            if((nums[prev] + nums[next] )*2== nums[crnt]){
                cnt++;
            }

        }
        return cnt;
        
    }
};