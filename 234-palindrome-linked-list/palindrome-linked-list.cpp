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
    bool isPalindrome(ListNode* head) {

       if (!head || !head->next)  return true;

    // Find middle
       ListNode* slow = head;
       ListNode* fast = head;

        while (fast->next && fast->next->next) {
           slow = slow->next;
           fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = slow->next;
        ListNode* prev = nullptr;

        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Compare
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            if (first->val != secondHalf->val)
                return false;

            first = first->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};