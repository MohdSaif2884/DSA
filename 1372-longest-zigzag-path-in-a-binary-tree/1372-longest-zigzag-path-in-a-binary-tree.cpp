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
int maxlen =0;
void f(TreeNode* root , int dir , int len){
    if(root == NULL){
        return ;
    }
    maxlen = max(maxlen , len);
    if(dir ==0){
        f(root->right, 1, len+1);
        f(root->left, 0, 1);
    }else{
        f(root->left, 0, len+1);
        f(root->right, 1, 1);
    }




}
    int longestZigZag(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        f(root, 0, 0);
        f(root, 1,0);
        return maxlen;
        
    }
};