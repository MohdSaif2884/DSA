class Solution {
public:
    int maxScore(string s) {

        int n = s.size();
        vector<int>zero(n);
        vector<int>one(n);

        int z =0;

        for(int i =0 ; i<n ; i++){
            if(s[i] =='0'){
                z++;
            }

            zero[i] = z;
        }

int o =0;
        for(int    i =n -1 ; i>=0 ; i--){
            if(s[i] =='1'){
o++;
            }
one[i] =o;

        }
int maxi =0;
        for(int i =0 ; i <n-1; i++){
        maxi =max(maxi , zero[i] + one[i+1]);
        }

        return maxi;
        
    }
};