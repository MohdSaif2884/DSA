class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int sum=0;
        int j =0;
        int maxi = INT_MIN;
        for(int i =0 ; i<n ; i++){
           

            // if(mp.find(nums[i])!=mp.end()){
            //     sum -=nums[j];
            // }

              
            while(mp.find(nums[i])!=mp.end()){
                mp.erase(nums[j]);
                 sum -=nums[j];
                 j++;
                
            }
             sum += nums[i];
              maxi = max(maxi , sum);

 
            mp[nums[i]]++;
 
        }
        return maxi;
        
    }
};