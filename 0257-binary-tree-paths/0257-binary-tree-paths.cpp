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
vector<string>ans;
void check(TreeNode * root,string path ){
    if(root== NULL){
        return ;
    }

    path+= to_string(root->val);
    if(root->left == NULL && root->right == NULL){
        ans.push_back(path);
    }

    path += "->";
    check(root->left, path);
    check(root->right, path);


}
    vector<string> binaryTreePaths(TreeNode* root) {
        
        check(root, "");
        return ans;
        
    }
};