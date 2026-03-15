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
    ListNode* sortList(ListNode* head) {
        //Insertion Sort (TLE) O(n^2)
        // ListNode *dummy = new ListNode(0);
        // ListNode *cu = head;
        // while(cu){
        //     ListNode *pre = dummy;
        //     while(pre->next && pre->next->val <= cu->val)
        //         pre = pre->next;
        //     ListNode *temp = cu->next;
        //     cu->next = pre->next;
        //     pre->next = cu;
        //     cu = temp;
        // }
        // return dummy->next;
        
        //merge
        if (!head || !head->next) return head;

        ListNode*left = head;
        ListNode*right = Divide(head);

        //recursive
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);

    }

private:
    ListNode * Divide(ListNode* head){
        ListNode* s = head;
        ListNode* f = head->next;

        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        ListNode *mid = s->next;
        s->next = nullptr;
        return mid; //回傳右半邊
    }

    ListNode* merge(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        //把剩的直接插上去
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;

        return dummy->next;
    }
};
