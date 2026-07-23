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
string ans ="~";
void check(TreeNode* root, string path){
     if(root == NULL){
            return ;
        }

        path += ('a'+ root->val);
        if(root->left == NULL && root->right == NULL){
            string ltor =path;
            reverse(ltor.begin(), ltor.end());
            if( ltor <ans){
                ans = ltor;

            }
           return ; 
        }

       check(root->left, path);
       check(root->right, path);

   

}
    string smallestFromLeaf(TreeNode* root) {
         check(root,"");
        return ans;
        
        
    }
};