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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int length = 0;
        ListNode *curr = head;
        
        while(curr){
            length++;
            curr = curr->next;
        }
        
        int partSize = ceil((double)length/k);
        int timesMax = 0;
        
        if(length == k){
            timesMax = k;    
        }
        else if((length%k)==0){
            timesMax = k;
        }
        else{
            timesMax = length%k;
        }
       
        curr = head;
        vector<ListNode *>ans;
        
        while(k--){
            
            if(!curr){
                ans.push_back(NULL);
                continue;
            }
            
            if(timesMax){
                timesMax--;
                
                ListNode *temp = new ListNode(-1);
                ListNode *head = temp;
                for(int i=0;i<partSize;i++){
                    temp->next = new ListNode(curr->val);
                    curr = curr->next;
                    temp = temp->next;
                }
                
                ans.push_back(head->next);
            }
            else{
                
                ListNode *temp = new ListNode(-1);
                ListNode *head = temp;
                for(int i=0;i<partSize-1;i++){
                    temp->next = new ListNode(curr->val);
                    curr = curr->next;
                    temp = temp->next;
                }
                
                ans.push_back(head->next);
            }
        }
        return ans;
    }
};