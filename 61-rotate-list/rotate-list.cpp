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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head||!head->next||k==0){
            return head;
         }
         ListNode*temp=head;
         int length=1;
         while(temp->next){
            temp=temp->next;
            length ++;
         }
         k=k%length;
         temp->next=head;
         int step=length-k;
         ListNode*newtemp=head;
         for(int i =0;i<step - 1;i++){
            newtemp=newtemp->next;
        
         }
         ListNode*newhead=newtemp->next;
         newtemp->next=NULL;
         return newhead;
         
        
    }
};