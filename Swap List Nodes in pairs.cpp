/*


Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(!A->next)
    {
        return A;
    }
    
    ListNode* curr = A;
    ListNode* Next = curr->next;
    ListNode* ans = Next;
    ListNode* tmp;
    ListNode* prev = NULL;
    while(curr!= NULL && Next!= NULL)
    {
        tmp = Next->next;
        Next->next = curr;
        curr->next = tmp;
        
        if(prev != NULL){
            prev->next = Next;
        }
        
        prev=curr;
        curr = curr->next;
        if(curr != NULL){
            Next = curr->next;    
        }
    }
    return ans;
    
}
