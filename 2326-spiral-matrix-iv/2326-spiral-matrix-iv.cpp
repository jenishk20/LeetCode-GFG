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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        
        vector<vector<int>>ans(n,vector<int>(m,-1));
        
        int i=0,j=0;
        int str = 0,enr = n-1;
        int stc = 0,enc = m-1;
     
        while(head){
            
            j = stc;
            i = str;

            while(head and j<=enc){
                ans[i][j] = head->val;
                head = head->next;
                j++;
            }

            str++;
            i = str;
            j = enc;
      
            while(head and i<=enr){
                ans[i][j] = head->val;
                head = head->next;
                i++;
            }
     
            enc--;
            i = enr;
            j = enc;
      
            while(head and j>=stc){
                ans[i][j] = head->val;
                head = head->next;
                j--;
            }

            enr--;
            i = enr;
            j = stc;

            while(head and i>=str){
                ans[i][j] = head->val;
                head = head->next;
                i--;
            }
            stc++;
        }

        return ans;
    }
};