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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head); //dummy node pointing to head
        ListNode* prev = dummy; //prev node pointing to dummy
        while (head != NULL) { 
            if (head->next != NULL && head->val == head->next->val) { //dupe checking
                while (head->next != NULL && head->val == head->next->val)
                    head = head->next;
                prev->next = head->next;  //last non dupe to next non dupe
            } else
                prev = prev->next;//no dupes
            head = head->next;//next node
        }
        return dummy->next; //return dummy
    }
};