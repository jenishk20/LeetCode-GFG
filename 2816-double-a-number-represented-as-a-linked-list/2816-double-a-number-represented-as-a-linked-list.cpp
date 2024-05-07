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
    
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        
        ListNode *reverseHead = reverse(head);
        
        int currentCarry = 0;
        
        ListNode *temp = reverseHead;
        while(temp){
            
            int val = 2 * temp->val + currentCarry;
            currentCarry = val/10;
            temp->val = val%10;
        
            if(temp->next == NULL){
                if(currentCarry){
                    temp->next = new ListNode(currentCarry);
                    break;
                }
            }
            temp = temp->next;    
        }
        
        return reverse(reverseHead);
    }
};