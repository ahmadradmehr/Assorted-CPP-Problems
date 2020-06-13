/* Partition List
 * 
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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

class PartitionList {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return head;
        ListNode* l1 = new ListNode, *head1 = l1, *l2 = head;
        while (l2 != NULL && l2->val < x) {
            l1->next = new ListNode(l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        head = l2;
        while (l2 != NULL && l2->next != NULL) {
            if (l2->next->val < x) {
                l1->next = new ListNode(l2->next->val);
                l1 = l1->next;
                l2->next = l2->next->next;
            } else {
                l2 = l2->next;
            }
        }
        l1->next = head;
        return head1->next;
    }
};