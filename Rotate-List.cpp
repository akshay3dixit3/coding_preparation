/*


Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int size = 0;
    if(!A->next)
    {
        return A;
    }
    ListNode*  head = A;
    
    while(head)
    {
        size++;
        head = head->next;
    }
    B = B%size;
    if(B==0)
    {
        return A;
    }
    int target = size-B+1;
    int tmp = 0;
    
    head = A;
    ListNode*  prev;
    while(tmp+1 != target && head!=NULL)
    {
        prev=head;
        head = head->next;
        tmp++;
    }
    prev->next=NULL;
    // cout<<prev->val;
    ListNode*  start;
    start = head;
    while(head->next)
    {
        head = head->next;
    }
    
    head->next = A;
    
    return start;
    
    
}
