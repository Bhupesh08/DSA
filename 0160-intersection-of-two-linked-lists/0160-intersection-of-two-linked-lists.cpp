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
        
        //Counting the number of Nodes in List A
        while(dummyA!=NULL) {
            countA++;
            dummyA = dummyA->next;
        }
        //Counting the number of Nodes in List B
        while(dummyB!=NULL) {
            countB++;
            dummyB = dummyB->next;
        }
        
        //offset is the difference between the length of both the lists
        int offset = abs(countA - countB);
        
        //Longer List ko utne ka headstart dedo jitna difference hai
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
        
        //Headstart de diya?? Haan! Badiya
        //Ab dono ko sath me chalayo, if at some moment they point to same node, return that node as it is the intersection point
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
