 class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // Shuru mein hum sirf index 0 tak jaa sakte hain
        
        for (int i = 0; i < n; i++) {
            // Agar main ek aise index par aa gaya jahan tak main kood hi nahi sakta tha
            if (i > maxReach) {
                return false; 
            }
            
            // Apne maxReach ko update karo
            // Ya toh purana maxReach bada hoga, ya naya jump (i + nums[i])
            maxReach = max(maxReach, i + nums[i]);
            
            // Optimization: Agar hum array ke end tak ya uske aage pahunch gaye, toh aage loop chalane ki zaroorat nahi
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};