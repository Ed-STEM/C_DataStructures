/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    
    // Fast pointer moves twice as fast as the slow pointer
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;      // Move slow pointer by one
        fast = fast->next->next;// Move fast pointer by two
    }
    
    // When fast pointer reaches the end, slow pointer will be at the middle.
    return slow;
    
    
}