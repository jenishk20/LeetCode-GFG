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
    ListNode* getKthNode(ListNode *temp,int k){
        k--;
        while(temp and k){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    void reverse(ListNode *temp){
        ListNode *prev = NULL;
        ListNode *curr = temp;

        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *temp = head;
        ListNode *prevLast = NULL;
        while(temp){
            ListNode *kthNode = getKthNode(temp,k);

            if(kthNode == NULL){
                if(prevLast){
                    prevLast->next = temp;
                    break;
                }
                break;
            }

            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;

            reverse(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;   
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};