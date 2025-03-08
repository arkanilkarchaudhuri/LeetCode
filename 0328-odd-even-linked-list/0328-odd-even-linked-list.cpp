class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* oddhead = head;
        ListNode* oddmover = oddhead;
        ListNode* evenhead = oddhead->next;
        ListNode* evenmover = evenhead;

        // Process odd and even nodes together
        while(oddmover->next && evenmover->next) {
            oddmover->next = evenmover->next;
            oddmover = oddmover->next;

            evenmover->next = oddmover->next;
            evenmover = evenmover->next;
        }

        oddmover->next = evenhead; // Connect odd list to even list

        return oddhead;
    }
};