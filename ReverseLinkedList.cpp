/* Reverse Linked List
 * 
 * Reverse a singly linked list.
 * 
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * Follow up:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *aftr;
        while (curr) {
            aftr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aftr;
        }
        return prev;
    }
};

// class ReverseLinkedList {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next)
//             return head;
//         ListNode *t = new ListNode(head->val);
//         while (head->next != NULL) {
//             head = head->next;
//             ListNode *tt = new ListNode(head->val, t);
//             t = tt;
//         }
//         return t;
//     }
// };