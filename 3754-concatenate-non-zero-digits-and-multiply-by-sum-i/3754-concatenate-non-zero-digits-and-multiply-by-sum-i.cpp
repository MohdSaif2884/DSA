class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        string str = "";
        long long sum =0;
        while(n >0){
            int l = n %10;
            if(l >0){
                str+= to_string(l);
                sum += l;
            }
            n = n/10;
        }

        reverse(str.begin(), str.end());
        // return str;
        // cout<<str;
        // cout<<sum;
        return stoi(str)*sum;
        
    }
};