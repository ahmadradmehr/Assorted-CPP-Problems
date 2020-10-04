/*
 * ### Add Two Numbers II ###
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
class AddTwoNumbers_II {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        int n = (v1.back() + v2.back()) % 10;
        int ext = (v1.back() + v2.back()) / 10;
        ListNode *l = new ListNode(n);
        v1.pop_back();
        v2.pop_back();
        while (!v1.empty() || !v2.empty() || ext) {
            if (!v1.empty() && !v2.empty()) {
                n = (v1.back() + v2.back() + ext) % 10;
                ext = (v1.back() + v2.back() + ext) / 10;
                v1.pop_back();
                v2.pop_back();
            } else if (!v1.empty()) {
                n = (v1.back() + ext) % 10;
                ext = (v1.back() + ext) / 10;
                v1.pop_back();
            } else if (!v2.empty()) {
                n = (v2.back() + ext) % 10;
                ext = (v2.back() + ext) / 10;
                v2.pop_back();
            } else {
                n = ext;
                ext = 0;
            }
            ListNode *t = new ListNode(n, l);
            l = t;
        }
        return l;
    }
};