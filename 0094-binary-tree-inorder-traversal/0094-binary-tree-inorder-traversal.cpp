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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > st ; 
        vector<int> a;
        TreeNode* curr = root;

        while(true){
            //left tak jaoo
            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }else{
                if(st.empty())break;

                //process the element

                curr = st.top();
                st.pop();
                a.push_back(curr->val);

                curr=curr->right;
            }
        }
    return a;

    }
};