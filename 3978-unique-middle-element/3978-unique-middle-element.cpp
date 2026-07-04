class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i =0; i<n ; i++){
            mp[nums[i]]++;
        }
        int mid = nums[n/2];
        if(mp[mid] >1){
            return false;
        }
        return true;
        
    }
};