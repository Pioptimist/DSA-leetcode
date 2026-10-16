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
    ListNode* f(ListNode* n , ListNode* m , int d){
        ListNode* temp = m;
        ListNode* tempp = n;
        while(d != 0){
            d--;
            temp = temp->next;
        }

        while(temp != tempp){
            temp = temp->next;
            tempp = tempp->next;
        }
        return temp;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0;
        int m = 0;
        ListNode* temp = headA;
        while(temp){
            n++;
            temp = temp->next;
        }
        ListNode* tempp = headB;
        while(tempp){
            m++;
            tempp = tempp->next;
        }
        if(n > m){
            return f(headB , headA , n - m);
        }
        else{
            return f(headA , headB , m - n);
        }

        
    }
};