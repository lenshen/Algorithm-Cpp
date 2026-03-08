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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *cu = head; //current
        while(cu != nullptr){
            ListNode *prev = dummy;
            while(prev->next && prev->next->val <= cu->val){
                prev = prev->next;
            }
            ListNode *temp = cu->next;
            cu->next = prev->next;
            prev->next = cu;
            cu = temp;
        }
        return dummy->next;
    }
};
