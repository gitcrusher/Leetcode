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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>res;
        if(root==nullptr)return {};
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            // cout<<q.size();
            int n = q.size();
            for(int i = 0 ; i < n; i++){
                cout << i<< " ";
                TreeNode* node = q.front();
                ans.push_back(node->val);
                q.pop();
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                
            }
        cout << endl;
            res.push_back(ans);
        }
        return res;

    }
};