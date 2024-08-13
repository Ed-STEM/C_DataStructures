/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    if ( head == NULL || left == right ) return head;
    
    int distance = right -left;
    int i = 0, j = 0;
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *previous = &dummy, *new = NULL;         

    
    // Move the previous node right before the left position
    while (previous != NULL && i < left-1 )
    {
        previous = previous->next;
        i++;
    }
    
    struct ListNode *current = previous->next;
    
   for (j=0;j< distance;j++)
   {
        new = current->next;
        current->next = new->next;
        new->next = previous->next;
        previous->next = new;
   }
        
    return dummy.next;
}