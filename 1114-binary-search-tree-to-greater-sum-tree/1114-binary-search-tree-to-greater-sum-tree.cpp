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
    void inorder(TreeNode* node, vector<int> &ans){
        if(node==NULL) return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    void replaceValues(TreeNode*  root, vector<int>& ans){
        if(root==NULL) return;

        replaceValues(root->left, ans);
        replaceValues(root->right,ans);

        int nodeSum = 0;
        for(auto it: ans){
            if(it >= root->val){
                nodeSum += it;
            }else{
                break;
            }
        }
        root->val = nodeSum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        reverse(ans.begin(),ans.end());

        replaceValues(root, ans);
        return root;
    }
};