/* Merge k Sorted Lists
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * 
 * Example:
 * Input:
 * [
 *  1->4->5,
 *  1->3->4,
 *  2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        ListNode* l = lists.at(0), *head = l;
        int ind = 0;
        if (head == NULL) {
            for (int i {0}; i < lists.size(); i++) {
                if (lists.at(i) != NULL) {
                    l = head = lists.at(i);
                    ind = i;
                    break;
                }
            }
            if (head == NULL)
                return NULL;
        }
        for (int i {0}; i < lists.size(); i++) {
            if (lists.at(i) == NULL || i == ind)
                continue;
            l = head;
            while (lists.at(i) != NULL) {
                ListNode* temp = new ListNode;
                temp->val = lists.at(i)->val;
                if (temp->val < head->val) {
                    temp->next = l;
                    head = temp;
                    l = head;
                } else {
                    while (l->next != NULL && temp->val > l->next->val) {
                        l = l->next;
                    }
                    if (l->next == NULL) {
                        l->next = temp;
                    } else {
                        temp->next = l->next;
                        l->next = temp;
                    }
                }
                lists.at(i) = lists.at(i)->next;
            }
        }
        return head;
    }
};