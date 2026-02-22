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
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+max(height(root->left),height(root->right));
    }

    void collectLevel(TreeNode* root, int level, vector<int>& temp) {
    if (!root) return;

    if (level == 1) {
        temp.push_back(root->val);
        return;
    }

    collectLevel(root->left, level - 1, temp);
    collectLevel(root->right, level - 1, temp);
}

    void traversal( TreeNode* root, int level, int maxLevel,vector<vector<int>>& ans){

        if (level > maxLevel)
        return;
        vector<int> temp;              // 🔹 har level par naya vector
        collectLevel(root, level, temp);
        ans.push_back(temp);
        traversal(root, level + 1, maxLevel, ans);


    }

    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> ans;
        int h = height(root);
        traversal(root, 1, h, ans);
        return ans;

    }
};