class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int n = s.size();
        int maxi = 0;
        int j =0;

        for(int i =0 ; i<n ; i++){
            mp[s[i]]++;

            while(mp[s[i]]>1){
                mp[s[j]]--;

                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            maxi = max(maxi, i -j +1);

        }
        return maxi;



        
    }
};