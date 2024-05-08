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
    vector<int>res;
    void inorder(TreeNode* root){
        if(!root){return;}
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* makeBST(int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode*root = new TreeNode(res[mid]);

        root->left = makeBST(start,mid-1);
        root->right = makeBST(mid+1,end);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int start =0;
        int end = res.size()-1;
        return makeBST(start,end);
    }
};