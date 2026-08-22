class Solution {
public:
    bool checkDivisibility(int n) {
int sum =0;
        if(n<10){
            return false;
        }
        int dup = n ;
        int prd =1;
        while(n){
            int a = n%10;
            sum+=a;
            prd = prd*a;
            n = n/10;
            
        }

        if(dup%(sum+prd) ==0){
            return true;
        }
        return false;
        
    }
};