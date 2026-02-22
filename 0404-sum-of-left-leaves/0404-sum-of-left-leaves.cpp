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

    void helper(TreeNode* root , int &s){
        if(root == nullptr ) return ;
        if(root->left &&
            root->left->left == nullptr &&
            root->left->right == nullptr){
            s+=root->left->val;
        }
        

        helper(root->left,s);
        helper(root->right,s);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;
        helper(root,s);
        return s;
    }
};