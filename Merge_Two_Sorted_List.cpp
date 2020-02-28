/*

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head;
    ListNode* currA = A;
    ListNode* currB = B;
    
    if(currA == NULL)
    {
        return B;
    }
    if(currB == NULL)
    {
        return A;
    }
    
    if(currA->val > currB->val)
    {
        head = currB;
        currB = currB->next;
    }
    else
    {
        head = currA;
        currA = currA->next;
    }
    
    ListNode* tmp = head;
    while(currA && currB)
    {
        if(currA->val > currB->val)
        {
            tmp->next = currB;
            tmp =  currB;
            currB = currB->next;
        }
        else
        {
            tmp->next = currA;
            tmp = currA;
            currA = currA->next;
        }
    }
    
    if(currB == NULL)
    {
        tmp->next = currA;
    }
    
    if(currA == NULL)
    {
        tmp->next = currB;
    }
    return head;
}
