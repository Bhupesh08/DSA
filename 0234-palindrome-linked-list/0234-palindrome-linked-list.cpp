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
        
        //using fast and slow pointer technique to make slow point to the middle of the given list
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        //Reversing the list from after that middle point
        //to make the comparison as we do in case of array possible
        ListNode* prev = NULL;
        ListNode* nex;
        while(slow!=NULL) {
            nex = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nex;
        }
        
        //now prev is pointing to the last element of the linked list
        //We could just compare like array now
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