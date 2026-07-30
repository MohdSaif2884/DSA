class Solution {
public:
    int distinctAverages(vector<int>& nums) {
unordered_set<int>st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
int cnt =0;
// int prev =INT_MIN;
        int i =0, j = n-1;
        while(i <=j){

            int avj = (nums[i]+ nums[j]);
// set.insert(avj);
            if(!st.count(avj)){
                cnt++;
            }


        st.insert(avj);
        i++;
        j--;
        }
          return cnt;
        
    }
   
};