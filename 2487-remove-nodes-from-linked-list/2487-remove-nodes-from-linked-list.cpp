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
    ListNode* removeNodes(ListNode* head) {
        
        ListNode *reverseHead = reverse(head);

        stack<int>se;
        
        ListNode *temp = reverseHead;
        
        int st = 0;
        
        map<ListNode *,bool>exists;
        while(temp){
            
            if(se.empty()){
                exists[temp] = false;
            }
            else if(se.top()>temp->val){
                exists[temp] = true;
            }
            else{
                while(!se.empty() && se.top()<=temp->val){
                    se.pop();
                }
                if(se.empty()){
                    exists[temp] = false;
                }
                else{
                    exists[temp] = true;
                }
            }
            se.push(temp->val);
            temp = temp->next;
        }
        
        temp = reverseHead;
        
        ListNode *prev = reverseHead;
        while(temp){
            
            if(exists[temp]){
                ListNode *next = temp->next;
                prev->next = next;
            }
            else{
                prev = temp;
            }
            temp = temp->next;
        }
        
        return reverse(reverseHead);
    }
};