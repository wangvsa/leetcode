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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *head = new ListNode(0);
            ListNode *node = head;
            ListNode *p = l1;
            ListNode *q = l2;

            int i = p ? p->val : 0;
            int j = q ? q->val : 0;
            node->val = ((i+j) % 10);
            int carray = (i+j) / 10;
            p = p->next;
            q = q->next;

            while(p || q) {
                i = p ? p->val : 0;
                j = q ? q->val : 0;
                node->next = new ListNode((i+j+carray) % 10);
                node = node->next;
                carray = (i + j + carray) / 10;
                p = p ? p->next : NULL;
                q = q ? q->next : NULL;
            }
            // 最后一位进位,eg.[5],[5],结果应为[0,1]
            if(carray)
                node->next = new ListNode(carray);

            return head;
        }
};
