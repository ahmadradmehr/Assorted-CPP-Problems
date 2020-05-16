/* Remove Nth Node From End of List
 * 
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * 
 * Example:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * 
 * Follow up:
 * Could you do this in one pass?
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class RemoveNthFromEnd {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size {0}, node_num {0};
        ListNode* node = head;
        while (node != NULL) {
            list_size++;
            node = node->next;
        }
        node = head;
        if (list_size - n == 0) {
            return head->next;
        }
        for (int i {0}; i < list_size; i++) {
            if (node_num == list_size - n - 1) {
                node->next = node->next->next;
                break;
            }
            node = node->next;
            node_num++;
        }
        return head;
    }
};