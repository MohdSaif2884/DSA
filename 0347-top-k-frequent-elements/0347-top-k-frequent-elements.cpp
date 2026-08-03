class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> res;

        for(int i =0 ; i< nums.size(); i++){
            res[nums[i]]++;
        }


        vector<pair<int , int>>ans(res.begin(),res.end());


        sort(ans.begin(),ans.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second> b.second;
        });

        vector<int>last;
        for(int i =0 ; i<k ; i++){
            last.push_back(ans[i].first);

        }
        return last;
        
    }
};