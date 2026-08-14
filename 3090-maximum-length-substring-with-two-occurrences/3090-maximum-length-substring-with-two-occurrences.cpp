class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i =0, j =0;
        unordered_map<int,int>mp;
        int maxi =0;
        while( i <n && j <n){
              mp[s[i]]++;

            while( mp[s[i]] >2){
                mp[s[j]]--;
                j++;
            }

            maxi = max(maxi , i-j+1);
           
            i++;

        }
        return maxi;
        
    }
};