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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>ma;
        for(auto it : nums) ma[it]++;

        ListNode *curr = head;
        while(curr and ma[curr->val]){
            curr = curr -> next;
        }

        head = curr;
        ListNode *prev = curr;
        curr = curr->next;

        while(curr){
            if(ma[curr->val]){
                prev->next = curr->next;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};