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
        set<ListNode*> hashset;
        
        //Storing the address of all the nodes of A LinkedList
        while(headA!=NULL) {
            hashset.insert(headA);
            headA = headA->next;
        }
        
        //Traversing the B LinkedList, If any address of A is found, means that is the intersection
        while(headB!=NULL) {
            if(hashset.count(headB)) {
                return headB;
            } else {
                headB = headB->next;
            }
        }
        
        return NULL;
    }
};