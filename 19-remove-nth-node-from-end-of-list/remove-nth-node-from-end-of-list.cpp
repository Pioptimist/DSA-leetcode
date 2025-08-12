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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        if(cnt == n){
            ListNode* newH = head->next;
            delete(head);
            return newH;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i =0;i<n;i++) fast= fast->next;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delN = slow->next;
        slow->next = slow->next->next;
        delete(delN);
        return head;
    }
};