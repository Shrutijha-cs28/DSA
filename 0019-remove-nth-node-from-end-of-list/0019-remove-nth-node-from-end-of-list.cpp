class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        
        int i = 0;
        while(temp!=nullptr){
            i++;
            temp = temp->next;
        }
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        temp = head;
        i=i-n;
        if(i == 0){
            return head->next;
        }
        while(i>1){
            temp = temp->next;
            i--;
        }
        temp->next = temp->next->next;
        return head;
    }
};