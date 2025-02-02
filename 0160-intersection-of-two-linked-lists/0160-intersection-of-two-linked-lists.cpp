/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> LL;

        while(headA!=NULL){
            LL.insert(headA);
            headA=headA->next;
        }
        while(headB!=NULL){
            if(LL.find(headB)!=LL.end()){
                return headB;
            }
                headB=headB->next;
        }
    return NULL;
    }
};