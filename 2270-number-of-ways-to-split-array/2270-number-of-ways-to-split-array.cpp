class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
int n = nums.size();

        vector<long long>pref(n);
        vector<long long>suff(n);
long long  sum =0;
        for(int i =0 ; i<n ; i++){
sum += nums[i];
pref[i] = sum ;
        }
sum =0;
        for(int i = n -1; i >=0; i--){
            sum += nums[i];
            suff[i] = sum ;

        }
int cnt =0;
        for(int i =0 ; i<n-1 ; i++){
            if(pref[i] >= suff[i+1]){
                cnt++;
            }

        }

        return cnt;

        
    }
};