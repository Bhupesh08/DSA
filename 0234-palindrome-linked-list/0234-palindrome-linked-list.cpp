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
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* nex;
        
        while(slow!=NULL) {
            nex = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nex;
        }
        
        //now prev is pointing to the last element of the linked list
        while(prev!=NULL) {
            if(head->val != prev->val) {
                return false;
            } else {
                head = head->next;
                prev = prev->next;
            }
            
        }
        
        return true;
        
    }
        
       
        
};