class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size()

        sort(nums.begin(),nums.end());

        int crnt = INT_MIN;
        int cnt =0;
        int largest = 1;
        int n = nums.size();
        if(n==0)return 0;

        for(int i =0 ; i<nums.size(); i++){
            if(nums[i] - 1 == crnt){
                cnt++;
                crnt = nums[i];

            }if(nums[i] != crnt){

                crnt = nums[i];
                cnt =1;
            }
            largest = max(largest, cnt);
        }

        // vector <int>ans(n,0);
return largest;
        
    }
};