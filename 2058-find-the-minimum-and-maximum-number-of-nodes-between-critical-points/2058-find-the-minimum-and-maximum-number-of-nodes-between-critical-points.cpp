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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      
        ListNode *temp = head;
        ListNode *prev = NULL;
     
        int mini = 1e9;
        int dist = 0;
 
        vector<int>ve;
        
        while(temp){
            
            if(prev and temp->next){
                
                int val = temp->val;
                int prevVal = prev->val;
                int nextVal = temp->next->val;
                
                if((val > prevVal and val > nextVal) || (val<prevVal and val<nextVal)){
                    
                    ve.push_back(dist);
                }
            }
            dist++;
            prev = temp;
            temp = temp->next;
        }
        
        if(ve.size()<2) return {-1,-1};
        
        for(int i=0;i<ve.size()-1;i++){
            mini = min(mini,ve[i+1]-ve[i]);
        }
        return {mini,ve[ve.size()-1] - ve[0]};
    }
};