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
    bool hasCycle(ListNode* head) {
        //Brute force, for cycle detection use hash sets
        unordered_set<ListNode*> hset;

        while(head){
            if(hset.find(head) != hset.end()){
                return true;
            } else{
                hset.insert(head);
            }
            head = head->next;
        }

        return false;
    }
};
