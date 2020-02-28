//CODE COPIED FROM https://github.com/royalpranjal/Interview-Bit/blob/master/Linked-Lists/ReorderList.cpp
// Found code a bit too teasing.
/*
iven a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,

reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* temp;
    ListNode* prev;
    ListNode* mid = A;
    ListNode* curr = A;
    ListNode* newCurr;
    ListNode* newHead;
    ListNode* newTemp;
    ListNode* newPrev;
    
    if(A == NULL || A->next == NULL){
        return A;
    }
    //TO FIND THE MID POINT FAST POINTER APPROACH.
    while(curr != NULL && curr->next != NULL){
        prev = mid;
        mid = mid->next;
        curr = (curr->next)->next;
    }
    
    prev->next = NULL;
    
    newCurr = mid;
    
    while(newCurr != NULL){
        newTemp = newCurr->next;
        if(newCurr == mid){
            newPrev = newCurr;
            newCurr->next = NULL;
            newCurr = newTemp;
        }
        else{
            newCurr->next = newPrev;
            newPrev = newCurr;
            newCurr = newTemp;
        }
    }
    
    newHead = newPrev;
    newCurr = newHead;
    curr = A;
    //SETTING UP THE REVERSED LIST FOR FINAL ANSWER,
    while(newCurr != NULL && curr != NULL){
        prev = curr;
        newPrev = newCurr;
        temp = curr->next;
        newTemp = newCurr->next;
        
        curr->next = newCurr;
        if(temp != NULL){
            newCurr->next = temp;
        }
        curr = temp;
        newCurr = newTemp;
    }
    
    return A;
}