class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        unordered_set<int>arr1(nums2.begin(), nums2.end());
        unordered_set<int>arr2(nums1.begin(), nums1.end());


        vector<int>a;
        for(auto i: arr2){
            if(!arr1.count(i)){
                a.push_back(i);
            }
        }
        ans.push_back(a);
vector<int>b;
        for(auto i:arr1){
            if(!arr2.count(i)){
b.push_back(i);
            }
        }

 ans.push_back(b);
        return ans;
        
    }
};