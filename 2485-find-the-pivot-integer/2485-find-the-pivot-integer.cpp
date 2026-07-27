class Solution {
public:
    int pivotInteger(int n) {

        for(int i =1 ; i <=n ; i++){
            int a = i* (i+1)/2;
            int c = i -1;
            int b = n* (n +1)/2  - c*( c+1)/2;

            if(a ==b){
                return i;
            }
        }

        return -1;
        
    }
};