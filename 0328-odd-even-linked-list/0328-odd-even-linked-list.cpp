
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // If list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Pointers for odd and even nodes
        ListNode* odd = head;
        ListNode* even = head->next;

        // Store the starting point of even list
        ListNode* evenHead = even;

        while (even != NULL && even->next != NULL) {

            // Connect odd nodes
            odd->next = even->next;
            odd = odd->next;

            // Connect even nodes
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};
