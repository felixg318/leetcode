/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int val = 0;
    struct ListNode* lptr = head;
    while (lptr != NULL) {
        val <<= 1;
        val |= lptr->val; 
        lptr = lptr->next;        
    }

    return val;
}
