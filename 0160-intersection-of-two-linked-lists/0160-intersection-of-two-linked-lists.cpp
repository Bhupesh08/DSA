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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int countA = 0, countB = 0;
        ListNode* dummyA = headA;
        ListNode* dummyB = headB;
        
        while(dummyA!=NULL) {
            countA++;
            dummyA = dummyA->next;
        }
        
        while(dummyB!=NULL) {
            countB++;
            dummyB = dummyB->next;
        }
        
        int offset = abs(countA - countB);
        
        if(countA > countB) {
            while(offset) {
                headA = headA->next;
                offset--;
            } 
        } else {
            while(offset) {
                headB = headB->next;
                offset--;
            }
        }
        
        while(headA!=NULL && headB!=NULL) {
            if(headA==headB) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
    
        return NULL;
    }
};