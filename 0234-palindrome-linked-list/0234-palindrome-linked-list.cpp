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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev=NULL;
        ListNode *next;
        ListNode *curr=head;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
       // cout<<slow->val<<endl;
        slow->next=reverse(slow->next);
        
        ListNode *st=head;
        ListNode *md=slow->next;
        while(st and md)
        {
            if(st->val!=md->val)
                return false;
            
            st=st->next;
            md=md->next;
        }
        return 1;
        
    }
};