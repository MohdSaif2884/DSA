class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_set<int>st(arr.begin(), arr.end());
        vector<int>temp(st.begin(), st.end());
        sort(temp.begin(), temp.end());

        unordered_map<int,int>mp;
        for(int i =0 ; i <temp.size(); i++){
            mp[temp[i]]= i+1;
        }

        vector<int>ans;
        for(int i =0 ; i<arr.size() ; i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
        
    }
};