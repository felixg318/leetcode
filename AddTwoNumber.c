/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int init = 0;

    struct ListNode* head;
    struct ListNode* tail;

    struct ListNode *l1ptr, *l2ptr;
    l1ptr = l1;
    l2ptr = l2;

    while (l1ptr != NULL || l2ptr != NULL){
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->next = NULL;

        if (carry) {
            carry = 0;
            if(l1ptr)
                l1ptr->val++;
            else if (l2ptr)
                l2ptr->val++;
        }

        if ( l1ptr != NULL && l2ptr != NULL)
            node->val = l1ptr->val + l2ptr->val;
        else if (l1ptr)
            node->val = l1ptr->val;
        else if (l2ptr)
            node->val = l2ptr->val;

        
        if (node->val > 9) {
            node->val %= 10;
            carry = 1;
        }

        if (!init) {
            head = node;
            tail = node;
            init = 1;
        }
        else {
            tail->next = node;
            tail = node;
        }

        //iter
        if (l1ptr)
            l1ptr = l1ptr->next;
        if (l2ptr)
            l2ptr = l2ptr->next;
        if (!l1ptr && !l2ptr)
            break;
    }

    if (carry) {
        carry = 0;
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;

        tail->next = node;
    }

    return head;
}
