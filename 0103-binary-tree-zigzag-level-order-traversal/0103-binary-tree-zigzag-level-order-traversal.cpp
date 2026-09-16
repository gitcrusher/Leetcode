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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode* >q;
        if(root==nullptr)return {};
        q.push(root);
        int count =0;
        while(!q.empty()){
            vector<int>ans;
            int n = q.size();
            for(int i = 0  ;i <n; i++ ){
                TreeNode* node = q.front();
                ans.push_back(node->val);
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right); 
                // if(count%2!=0){
                //     if(node->left!=nullptr) q.push(node->left);
                //     if(node->right!=nullptr) q.push(node->right);
                // }else{
                //     if(node->right!=nullptr) q.push(node->right);
                //     if(node->left!=nullptr) q.push(node->left);
                // }
            }
            cout<< count<<endl;
            if(count%2!=0){
                reverse(begin(ans),end(ans));
            }
            count++;
            res.push_back(ans);
        }
        return res;
    }
};