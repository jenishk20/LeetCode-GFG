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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode *start = head->next;
        ListNode *ans = start;
        
        ListNode *temp = head->next;
        
        while(temp){
            
            int sum = 0;
            while(temp and temp->val!=0){
                
                sum += temp->val;
                temp = temp->next;
                
            }
            
            start->val = sum;
            start->next = temp->next;
            start = start->next;
            temp = temp->next;
            
        }
        return ans;

    }
};