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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;           // copy next node's value
        ListNode* temp = node->next;           // store next node
        node->next = node->next->next;         // bypass next node
        delete temp;                           // delete the original next node
    }
};
