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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pointer = dummy;

        while (pointer->next != nullptr && pointer->next->next != nullptr) {
            ListNode* s1 = pointer->next;
            ListNode* s2 = pointer->next->next;

            s1->next = s2->next;
            s2->next = s1;
            pointer->next = s2;

            pointer = s1;
        }
        return dummy->next;
    }
};