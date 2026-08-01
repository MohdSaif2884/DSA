class Solution {
public:
    int countValidPrefixes(string s) {

        int n = s.size();

        int z =0;
        int one =0;
        int cnt =0;
        for(int i =0; i<n ; i++){
            if(s[i]=='0'){
                z++;
            }else{
                one++;
            }

            if(abs(z-one) <=1){
                cnt++;
            }
        }
        return cnt;
        
    }
};