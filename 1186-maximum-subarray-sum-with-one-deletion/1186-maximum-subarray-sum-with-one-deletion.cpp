class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int prev =arr[0];
        int maxi = arr[0];
        int del =0;

        // int mini = arr[0];
        for(int i =1; i<n ; i++){
            del = max(prev , del + arr[i]);
            prev = max(arr[i], prev+arr[i]);
            maxi = max(maxi,max(del , prev));
        }
        return maxi ;
        
    }
};