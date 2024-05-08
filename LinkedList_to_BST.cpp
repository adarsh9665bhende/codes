/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
   
    // approach 1 using space//

    // vector<int>res;
    // TreeNode* makeBST(int start,int end){
    //     if(start>end){
    //         return NULL;
    //     }
    //     int mid = (start+end)/2;
    //     TreeNode*root = new TreeNode(res[mid]);

    //     root->left = makeBST(start,mid-1);
    //     root->right = makeBST(mid+1,end);

    //     return root;

    // }


    // approach 2 without using space //

    TreeNode* makeBST(ListNode*start,ListNode*end){
        if(start==end){
            return NULL;
        }
        ListNode*slow=start;
        ListNode*fast=start;
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode*root = new TreeNode(slow->val);
        root->left = makeBST(start,slow);
        root->right = makeBST(slow->next,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // while(head){
        //     res.push_back(head->val);
        //     head=head->next;
        // }
        // return makeBST(0,res.size()-1);

        // approach 2
        return makeBST(head,NULL);
    }
};