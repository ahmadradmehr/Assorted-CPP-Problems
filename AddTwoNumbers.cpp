/* You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = NULL, *ll = NULL;
        int n {0};
        while (l1 || l2 || n != 0) {
            if (!l) l = new ListNode(0);
            else {
                l->next = new ListNode(0);
                l = l->next;
            }
            if (!ll) ll = l;
            if (!l1 && !l2) {
                l->val = n;
                n = 0;
            }
            else if (l1 && l2) {
                l->val = (l1->val+l2->val+n)%10;
                n = (l1->val+l2->val+n)/10;
                l1 = l1->next;
                l2 = l2->next;
            } else if (!l1) {
                l->val = (l2->val+n)%10;
                n = (l2->val+n)/10;
                l2 = l2->next;
            } else if (!l2) {
                l->val = (l1->val+n)%10;
                n = (l1->val+n)/10;
                l1 = l1->next;
            }
        }
        return ll;
    }
};