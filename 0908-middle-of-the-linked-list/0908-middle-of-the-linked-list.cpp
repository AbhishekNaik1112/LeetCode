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
    ListNode* middleNode(ListNode* head) {
        int ct = 0;
        ListNode* dummy = head;
        while(dummy!=nullptr){
            dummy=dummy->next;
            ct++;
        }
        int mid = ct/2;
        ListNode* temp = head;
        int j=0;
        while(j<mid){
            temp=temp->next;
            j++;
        }
        return temp;
    };
};