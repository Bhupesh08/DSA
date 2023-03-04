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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool isloopPresent = false;
        
        //Checking if loop is present or not
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                isloopPresent = true;
                break;
            }
        }
        
        
        //If loop is present, then move slow pointer to the start of the linked list.
        //Move both slow and fast at the same speed of one till they meet.
        //the point where they meet is the starting point of the loop/cycle.
        if(isloopPresent) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        
        return NULL;

    }
};
