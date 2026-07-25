/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i =0 ; i <size; i++){

                Node * crnt = q.front();
                q.pop();
                temp.push_back(crnt->val);
                for(Node * child: crnt->children){
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};