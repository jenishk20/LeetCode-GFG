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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,
        greater<pair<int,ListNode *>>>pq;

        for(auto it : lists){
            if(it != NULL){
                pq.push({it->val,it});
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            temp->next = curr.second;
            temp = temp->next;

            if(curr.second->next){
                pq.push({curr.second->next->val,curr.second->next});
            }
        }
        return dummy->next;

    }
};