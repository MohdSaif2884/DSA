class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>mp;
        

        for(int i =0 ; i<nums.size(); i++){
            mp[nums[i]] =i;
        }
        // return nums;

        for( auto i:operations ){
            int old = i[0];
            int newv = i[1];

            int index = mp[old];
            nums[index] = newv;

            mp.erase(old);
            mp[newv]= index;
        }

        return nums;
        
    }
};