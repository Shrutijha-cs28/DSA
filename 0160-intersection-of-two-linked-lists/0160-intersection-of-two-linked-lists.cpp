
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
    ListNode *getIntersectionNode(ListNode *headA,
                                  ListNode *headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {

            // If pA reaches end, move to headB
            if (pA == NULL) {
                pA = headB;
            } else {
                pA = pA->next;
            }

            // If pB reaches end, move to headA
            if (pB == NULL) {
                pB = headA;
            } else {
                pB = pB->next;
            }
        }

        // Returns intersection node or NULL
        return pA;
    }
};
