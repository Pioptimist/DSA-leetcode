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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int psum = 0;
        map<int,ListNode*> mpp;
        ListNode* dummyN = new ListNode(0);
        dummyN->next = head;
        mpp[0] = dummyN;
        while(head!=NULL){
            psum += head->val;
            if(mpp.find(psum)!=mpp.end()){
                ListNode* start = mpp[psum];
                ListNode* temp = start;
                int prefS = psum;
                while(temp!=head){
                    temp = temp->next;
                    prefS += temp->val;
                    if(temp!=head){
                        mpp.erase(prefS);
                    }
                }
                start->next = head->next;
            } 
            else{
                mpp[psum] = head;
            }
            head = head->next;
        }
        return dummyN->next;
    }
};