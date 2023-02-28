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
    ListNode* removeElements(ListNode* head, int val) {
        
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            if(temp->val == val) {
                count++;
            }
            temp = temp->next; 
        }
        
        while(head!=NULL && head->val==val) {
            temp = head;
            head = head->next;
            delete temp;
            count--;
        }
        
        while(count--) {
            ListNode* prev = head;
            ListNode* curr = head;

            while(curr->val != val) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            delete curr;
        }
        
        return head;
    }
};