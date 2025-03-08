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
    int pairSum(ListNode* head) {
        
        int sum = 0;
        vector<int> vec;

        while(head != nullptr)
        {
            vec.push_back(head->val);
            head = head -> next;
        }

        int n = vec.size();

        for(int i=0; i< n/2; i++)
        {
            sum = max(sum, vec[i] + vec[n-i-1]);
        }

        return sum;
    }
};