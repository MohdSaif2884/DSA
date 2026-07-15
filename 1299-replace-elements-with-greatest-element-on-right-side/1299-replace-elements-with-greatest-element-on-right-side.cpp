class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>ans(n);
        ans[n-1] = -1;
        int maxi = -1;

        for(int i =n-2 ; i >=0 ; i--){
            if(arr[i+1] > maxi){
                maxi = arr[i+1];
                
            }
            ans[i]=maxi;
            

        }
        return ans;
        
    }
};