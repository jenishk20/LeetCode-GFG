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
        ListNode *curr=head;
        ListNode *next=NULL;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return;
        ListNode *slow = head;
        ListNode *fast = head;

        
        
        while(fast && fast->next){
          
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev=NULL;
        ListNode *next=NULL;
        ListNode *curr=slow;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        ListNode *l1=head;
        ListNode *l2=prev;
        ListNode *temp;
        
        cout<<l2->val<<endl;
        while(l2->next)
        {
            temp=l1->next;
            l1->next=l2;
            l1=temp;
            
            temp=l2->next;
            l2->next=l1;
            l2=temp;
        }
       
      

        
        
       
    }
};