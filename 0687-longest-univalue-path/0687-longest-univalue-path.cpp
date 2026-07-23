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
int ans =0;
int dfs(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int l = dfs(root->left);
    int r= dfs(root->right);

    int leftval =0;
    int rightv=0;

    if(root->left && root->left ->val == root->val){
        leftval = 1+l;
    }

    if(root->right && root->right->val == root->val){
        rightv = r+1;
    }
    ans = max(ans , leftval + rightv);

    return max(leftval, rightv);
}
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        dfs(root);
        return ans;


        
    }
};