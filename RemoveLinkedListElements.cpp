/* Remove Linked List Elements
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
class RemoveLinkedListElements {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
            head = head->next;
        if (head == NULL)
            return NULL;
        ListNode* l = head;
        while (l->next != NULL) {
            if (l->next->val == val) {
                l->next = l->next->next;
            } else {
                l = l->next;
            }
        }
        return head;
    }
};