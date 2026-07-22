class Solution {
public:
 
    bool isArraySpecial(vector<int>& nums) {
        int i =0 ; 
        int j =1;

        int n = nums.size();
         if(n <=1){
            return true;
         }
int prev =-1;
         if(nums[0]%2 ==0){
            prev =0;
         }else{
prev =1;
         }
int crnt =-1;
         for(int i =1 ; i<n ;i++){
             if(nums[i]%2 ==0){
            crnt =0;
         }else{
crnt =1;
         }


         if(crnt ==prev){
            return false;
         }
         cout<<prev<<endl;
         cout<<crnt;
         

         prev = crnt ;

         }
         return true;
    }
};