/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root->val %2 ==0){
            return false;
        }

        queue<TreeNode*>q;
        q.push(root);
        int j=0;
        while(!q.empty()){
            int size = q.size();
            int prev =0;
           if(j % 2 == 0)
    prev = INT_MIN;
else
    prev = INT_MAX;
            for(int i =0 ; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                 if(j %2==0){
                    if(prev >=node->val){
                        return false;
                    }
                 }else{
                    if(prev<= node->val){
                        return false;
                    }
                 }
                if( j%2 ==0 && node->val %2 ==0){
                    return false;
                }

                if(j %2 ==1 && node->val %2 ==1){
                    return false;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                prev =node->val;

            }
            j++;
            
        }
        return true;
        
    }
};