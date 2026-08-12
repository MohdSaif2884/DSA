class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();

        int i =0;
        int maxi =0;
int j =0;
        while(i <n){
            mp[nums[i]]++;
            while(mp[nums[i]] >k && j <n){
                
                mp[nums[j]]--;
                j++;
            }
            maxi = max(maxi ,i-j+1);
            cout<<maxi;
i++;

        }

        return maxi;
        
    }
};