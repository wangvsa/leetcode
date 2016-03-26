/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
            
        ListNode *p1 = head;
        ListNode *p2 = p1->next;
        head = p2;
        
        ListNode *tmpp1;
        
        while(p1 != NULL && p2 != NULL) {
            if(p2->next!=NULL) {
                p1->next = p2->next;                // p1->next = p3;
                if(p2->next->next!=NULL)
                    p1->next = p2->next->next;      // p1->next = p4;
            } else {
                p1->next = NULL;
            }
            tmpp1 = p2->next;
            p2->next = p1;
        
            p1 = tmpp1;
            if(p1 != NULL)
                p2 = p1->next;
        }
        return head;
    }
};