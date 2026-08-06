class Solution {
public:
int degm(int n ){
    int l =1 ;
    while( n >0){
         int r = n %10;
         l = l*r;
        n = n/10;
    }
    // cout<<l;
    return l;
}
    int smallestNumber(int n, int t) {

        for(int i = n ; i <= n+10; i++){
            if(degm(i)%t ==0){
                cout<< degm(i);
                return i;
            }
        }

        return -1;
        
    }
};