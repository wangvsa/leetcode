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
    int min(ListNode *n1, ListNode *n2) {
        return (n1->val < n2->val) ? n1->val : n2->val;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head, *p;
        
        if(p1->val < p2->val){
            head = new ListNode(p1->val);
            p1 = p1->next;
        } else {
            head = new ListNode(p2->val);
            p2 = p2->next;
        }
        p = head;
        
        while(p1!=NULL || p2!=NULL) {
            if(p1!=NULL && p2!=NULL) {
                if(p1->val < p2->val){
                    p->next = new ListNode(p1->val);
                    p1 = p1->next;
                } else {
                    p->next = new ListNode(p2->val);
                    p2 = p2->next;
                }
            } else if(p1!=NULL) {
                p->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                p->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            p = p->next;
        }
        
        return head;
    }
};