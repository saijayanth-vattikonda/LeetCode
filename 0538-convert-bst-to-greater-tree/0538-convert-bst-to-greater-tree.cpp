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

class Solution{
public:
    TreeNode* convertBST(TreeNode* root){
        int nodeSum = 0;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(!st.empty() || node != NULL){
            while(node != NULL){
                st.push(node);
                node = node->right;
            }
            // Store the top value of stack in node and pop it.
            node = st.top();
            st.pop();

            // Update value of node.
            nodeSum += node->val;
            node->val = nodeSum;
            
            node = node->left;
        }
        return root;
    }
 };
// class Solution {
// private:
//     void helper(TreeNode* root,int &nodeSum){
//         if(root==NULL) return;

//         helper(root->right, nodeSum);
//         nodeSum += root->val;
//         root->val = nodeSum;
//         helper(root->left,nodeSum);
//     }
// public:
//     TreeNode* convertBST(TreeNode* root) {
//         int nodeSum = 0;
//         helper(root, nodeSum);
//         return root;
//     }
// };