/* Reorder List
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example 1:
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 */
 
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
class ReorderList {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *p = head, *q = head;
        while (q && q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        ListNode *rev = p->next;
        p->next = NULL;
        p = head;
        rev = reverseList(rev);
        q = p->next;
        while (q && rev) {
            p->next = rev;
            rev = rev->next;
            p = p->next;
            p->next = q;
            q = q->next;
            p = p->next;
        }
        if (q)
            p->next = q;
        if (rev)
            p->next = rev;
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode *a = NULL, *b = head, *c;
        while (b) {
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }
};