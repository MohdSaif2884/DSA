class Solution {
public:
    bool isLongPressedName(string name, string typed) {

        int n = typed.size();
        int m = name.size();
        int j =0;

        for(int i =0 ; i<n ; i++){
            if( typed[i]== name[j] && j <m){
                j++;
            }else if( i >0 && typed[i] == typed[i-1]){

            }else{
                return false;
            }

        }
// cout<<j;
cout<<m-1;
        return j==m;
        
    }
};