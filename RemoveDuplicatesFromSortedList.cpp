/* Remove Duplicates from Sorted List
 * 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
 * 
 * Example 2:
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class DeleteDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *A = head;
        while (A && A->next) {
            if (A->next->val == A->val) {
                A->next = A->next->next;
            } else
                A = A->next;
        }
        return head;
    }
};