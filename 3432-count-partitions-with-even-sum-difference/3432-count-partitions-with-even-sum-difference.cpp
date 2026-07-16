class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum =0;
         int n = nums.size();
         vector<int>suff(n);
        //  suff[n-1]= nums[n-1];
        int ss=0;
         for(int i =n-1; i>=0 ; i--){
             ss+=nums[i];
            suff[i]= ss;

         }
        //  int sum =0
        int cnt =0;
         for(int i =0 ; i<n-1 ; i++){

            sum+= nums[i];

            if(( suff[i+1]- sum)%2==0){
                cnt++;
            }
            
         }
         return cnt;

    }
};