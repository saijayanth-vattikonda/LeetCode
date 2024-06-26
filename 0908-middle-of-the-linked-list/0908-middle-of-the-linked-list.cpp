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
    ListNode* middleNode(ListNode* head) {
        // BRUTE FORCE
        // ListNode* temp = head;
        // int length = 0;
        // while(temp!=NULL){
        //     length++;
        //     temp = temp->next;
        // }
        // temp = head;
        // for(int i=0;i<length/2;i++){
        //     temp = temp->next;
        // }
        // return temp;

        // Optimal Approach(Slow and fast Pointer)
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};