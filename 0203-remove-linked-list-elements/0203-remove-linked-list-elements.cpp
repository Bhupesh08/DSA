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
        
        //To count the no of occurrences of the node with value val, it will be later usefull as we will know how much times we have to execute the deletion node method
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            if(temp->val == val) {
                count++;
            }
            temp = temp->next; 
        }
        
        //To take care of the cases like [7,7,7,3,4] || [8,8,8,8], cases likes these needs to be handled separately.
        while(head!=NULL && head->val==val) {
            temp = head;
            head = head->next;
            delete temp;
            count--;
        }
        
        //The main part
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