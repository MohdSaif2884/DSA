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

void maparent(unordered_map<TreeNode*, TreeNode*>&parentrack , TreeNode *root){
    if(root==NULL){
        return ;
    }

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(it->left){
            parentrack[it->left] = it;
            q.push(it->left);
        }

        if(it->right){
            parentrack[it->right] = it;
            q.push(it->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*>parentrack;
        unordered_set<TreeNode*>vis;

        maparent(parentrack,root);
        vis.insert(target);

        queue<TreeNode*>q;
        q.push(target);
        int level =0;
        while(!q.empty()){
            int size = q.size();
            if(level == k){
                break;
            }

            for(int i =0 ; i<size; i++){

                // if(level == k){}

                auto crnt = q.front();
                q.pop();

                if(crnt->left && vis.find(crnt->left)== vis.end()){
                    q.push(crnt->left);
                    vis.insert(crnt->left);
                }

                if(crnt->right && vis.find(crnt->right) == vis.end()){
                    q.push(crnt->right);
                    vis.insert(crnt->right);
                }

                if(parentrack[crnt]  &&  vis.find(parentrack[crnt]) == vis.end()){
                    q.push(parentrack[crnt]);
                    vis.insert(parentrack[crnt]);
                }

            }
            level++;
        }

        vector<int>ans;

        while(!q.empty()){
            int n = q.size();

            for(int i =0 ; i<n ; i++){
                auto crnt = q.front();
                q.pop();
                ans.push_back(crnt->val);
            }
        }

        return ans;
        
    }
};