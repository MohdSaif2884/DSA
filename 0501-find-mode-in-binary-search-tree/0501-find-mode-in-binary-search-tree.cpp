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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int>mp;
         if(root == nullptr)
            return {};


        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            // int n = q.size();
              TreeNode* node = q.front();
              q.pop();
              mp[node->val]++;

              if(node->left){
                q.push(node->left);
              }

              if(node->right){
                q.push(node->right);
              }



        }
        int maxi =0;
        int a =0;
        for(auto it:mp){
            if(it.second > maxi){
                maxi = it.second;
                // a= it.first;

            }
        }
   vector<int>ans;
        for(auto it:mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
      
        // ans.push_back(a);

        return ans;
    }
};