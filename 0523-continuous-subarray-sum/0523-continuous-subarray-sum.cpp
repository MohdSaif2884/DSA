class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {  

         
        unordered_map<int, int> mp;
        mp[0] = -1;

        long long pref = 0;
        int ans = nums.size();
int z =0;
        for (int i = 0; i < nums.size(); i++) {
// if( nums[i] ==0 ){
//      z++;
//      if(z >=2){
//         return true;
//      }
// }else z =0;
            pref += nums[i];

            int curr = pref % k;
            

            if (mp.count(curr)){
               if(i - mp[curr] >=2){
                return true;
               } }else{
                mp[curr] = i;
               }

             
        }

       return false; 
    }
};