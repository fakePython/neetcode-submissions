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
    ListNode* rreversed(ListNode* head, ListNode* reversed){
        if(head == nullptr) {
            return reversed;
        }
        
        ListNode* nextNode = head->next;
        head->next = reversed;

        return rreversed(
            nextNode, head);
    }
    /***
    head = 1 2 3
    reversed = 0;

    -> newHead = 1
        newHead->next = 0 : newHead = 1 0

    head = 2 3
    reversed = 1 0

    -> newHead = 2;
       newHead->next = 1 : newHead = 2 1 0

       return 

    head = 3
    reversed = 2 1 0

    ->> head->next == null
        last = 3
        last->next = 2 1 0 : last 3 2 1 0 (return 3 2 1 0)
    
    */
    ListNode* reverseList(ListNode* head) {

        // return rreversed(head, nullptr);

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
