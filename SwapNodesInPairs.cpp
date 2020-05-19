/* Swap Nodes in Pairs
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * 
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class SwapNodesInPairs {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *l1 = head, *next = head->next;
        l1->next = l1->next->next;
        next->next = l1;
        head = next;
        while (l1->next != NULL && l1->next->next != NULL) {
            ListNode *l2 = l1->next;
            l1->next = l1->next->next;
            l2->next = l2->next->next;
            l1->next->next = l2;
            l1 = l1->next->next;
        }
        return head;
    }
};