class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
sort(nums.begin(), nums.end());
        int min = nums[0];
        int maxi = nums[n -1];
        vector<int>ans;
int j =0;
        for(int i = min ; i <= maxi ; i++){
if(i != nums[j]){
    ans.push_back(i);
}else{
    j++;
}
        }

        return ans;

        
    }
};