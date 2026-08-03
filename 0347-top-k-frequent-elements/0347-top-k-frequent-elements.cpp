class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i =0 ;i<n ; i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>>ans(mp.begin(), mp.end());
sort(ans.begin(), ans.end(), [](auto & a, auto & b ){
    return a.second >b.second;
});

vector<int>arr;
for(int i =0 ; i < k ;i++){
    arr.push_back(ans[i].first);
}
        return arr;
    }
};