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
    ListNode* findmid(ListNode* head)
    {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        
        while(slow_ptr && fast_ptr && fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        ListNode* mid_ptr = slow_ptr->next;
        slow_ptr->next = NULL;
        
        return mid_ptr;
    }
    
    ListNode* reverse_list_from_mid(ListNode* head)
    {
        if(!head)
            return NULL;
        
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    void merge(ListNode* p, ListNode* q) {
        if(!p) return;
        if(!q) return;
        
        while(p && q) {
            ListNode* pTemp = p->next;
            ListNode* qTemp = q->next;
            p->next = q;
            p = pTemp;
            q->next = p;
            q = qTemp;
        }
    }
    
    void reorderList(ListNode* head) {
        // if(!head)
        //     return;
        // vector<int> v;
        // ListNode *tmp=head;
        // while(tmp)
        // {
        //     v.push_back(tmp->val);
        //     tmp = tmp->next;
        // }
        // tmp = head;
        // int st=0, end=v.size()-1, flag=0;
        // while(st<=end)
        // {
        //     if(flag%2==0)
        //         tmp->val = v[st++];
        //     else
        //         tmp->val = v[end--];
        //     flag++;
        //     tmp = tmp->next;
        // }
        if (!head)
            return;
        
        ListNode* mid = findmid(head);
        
        mid = reverse_list_from_mid(mid);
        
        merge(head, mid);
    }
};