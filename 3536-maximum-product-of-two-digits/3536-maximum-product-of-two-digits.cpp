class Solution {
public:
vector<int>arr;
void f(int n ){
    while(n >0){
        int l = n %10;
        arr.push_back(l);
        n = n/10;

    }

}

 
    int maxProduct(int n) {
        f(n);
        int maxi =0;
cout<<arr[0];
        int m = arr.size();
        for(int i =0 ; i<m ; i++){
            for(int j = i+1; j<m ; j++){
                long long temp ;
                temp = arr[i]* arr[j];
                if(temp >maxi ){
                    maxi = temp;
                    // cout<<maxi;
                }

            }
        }
        return maxi;
        
    }
};