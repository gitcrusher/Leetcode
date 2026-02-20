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
    
    int level(TreeNode* root){
        if(root==nullptr) return 0; 
        return 1 + max(level(root->left),level(root->right));
    }

    void helper(TreeNode* root, int &diameter){
        if(root==nullptr) return ;
        int dia = levels(root->left)+levels(root->right);


        diameter = max(diameter, dia);

       helper(root->left);
       helper(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};