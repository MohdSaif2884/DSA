/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // return target;
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
            auto crnt = q.front();
            q.pop();

            if(crnt->val == target->val){
                return crnt;
            }

            if(crnt->left){
                q.push(crnt ->left);
            }

            if(crnt->right){
                q.push(crnt->right);
            }
        }return NULL ;
    }
};