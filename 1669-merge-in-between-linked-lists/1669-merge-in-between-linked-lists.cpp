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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *dummy=new ListNode(-1);
        dummy->next=list1;
        
        a--;
        int forward=b-a;
       
        while(a--)
        {
            list1=list1->next;
        }
        ListNode *temp=list1;
        cout<<list1->val<<endl;
        while(forward--)
        {
            list1=list1->next;
        }
        ListNode *attach=list1->next;
        cout<<list1->val<<endl;
        
        while(list2)
        {
            temp->next=list2;
            temp=temp->next;
            list2=list2->next;
        }
        temp->next=attach;
        
        
        return dummy->next;
    }
};