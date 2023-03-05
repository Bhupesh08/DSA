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
        ListNode* dummy = new ListNode(0, head);
        ListNode* prim = dummy;  //Primary Pointer
        ListNode* temp = head;
        
        //taking the temp pointer to its each initial required position
        while(n && temp != NULL) {
            temp = temp->next;
            n--;
        }
        
        //Moving both temp and prim till prim reaches at the node just before the one we want to delete
        while(temp != NULL) {
            temp = temp->next;
            prim = prim->next;
        }
      
        //Deleting that fucking node
        prim->next  = prim->next->next;
        
        return dummy->next;
    }
};