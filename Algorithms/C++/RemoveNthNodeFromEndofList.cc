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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n < 0 || head==NULL)
            return head;
            
        ListNode *p1 = head, *p2 = head;
        for(int i=0;i<n;i++) {
            if(p2!=NULL)
                p2 = p2->next;
            else {    // n比节点个数还大
                return head;
            }
        }
        
        // 删除第一个节点
        if(p2==NULL)
            return p1->next;
        
        while(p2->next!=NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};