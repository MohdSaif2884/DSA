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
    bool isCousins(TreeNode* root, int x, int y) {

        unordered_map<int,int>mp;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int found =0;

             for(int i =0 ; i<size ; i++){
                auto crnt = q.front();
                q.pop();
if(crnt->val == x || crnt->val == y){
    found++;
}
                if(crnt->left){
                    q.push(crnt->left);
                    mp[crnt->left->val]= crnt->val;
                }
                if(crnt->right){
                    q.push(crnt->right);
                    mp[crnt->right->val] = crnt->val;
                }
             }

             if(found == 2 && mp[x] != mp[y]){
                return true;
             }


        }
        return false;
        
    }
};