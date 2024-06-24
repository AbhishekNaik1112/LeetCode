// Two pointers
// sp 1
// fp 2

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* sp = head;
        ListNode* fp = head;

        // if(head==nullptr) return false;

        while (sp!=nullptr && sp->next != nullptr && fp->next != nullptr && fp->next->next!=nullptr) {
            sp = sp->next;
            fp = fp->next->next;
            if (sp == fp)
                return true;
        }
        return false;
    }
};