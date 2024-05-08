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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next){return true;}
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode*head2 = slow->next;
        ListNode*before =NULL;
        while(head2){
            ListNode*temp=head2->next;
            head2->next=before;
            before = head2;
            head2=temp;
        }
        
        ListNode*p1=head;
        ListNode*p2=before;
        while(p2){
            if(p1->val != p2->val){return false;}
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};