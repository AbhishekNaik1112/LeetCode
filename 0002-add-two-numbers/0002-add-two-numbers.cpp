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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL; //if both ll empty return null
        else if (l1 == NULL) return l2; // if l1 null return l2
        else if (l2 == NULL) return l1; // if l2 null return l1
        int a = l1->val + l2->val; // add vals
        ListNode* p = new ListNode(a % 10); // create node to manage carryovers
        p->next = addTwoNumbers(l1->next, l2->next); //recursion to manage next nodes
        if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1)); //if a > 10  carryover to next node
        return p; //return node which you created
    }
};
