/************
  LeetCode Reorder List 

  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

  You must do this in-place without altering the nodes' values.

  For example,
  Given {1,2,3,4}, reorder it to {1,4,2,3}.

  Discussion:
  step1 find the middle node of the linked list (using the slow/fast pointers)
  step2 reverse the second half of the linked list
  step3 insert each element in the second part in between the elements of the
        first half.

  time complexity O(n), space complexity O(1)
***********************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *p = head;
        ListNode *q = head;
        
        // find the middle node
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        
        // now p is the middle node
        // reverse the second half
        q = p->next;
        while (q->next) {
            ListNode *tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next =tmp;
            
        }
        
        // now p->next points to the end of element
        // re-order the list from head
        q = head;
        while (p->next && q != p) {
            ListNode *tmp = q->next;
            q->next = p->next;
            p->next = p->next->next;
            q->next->next = tmp;
            q = tmp;
        }
    }
};
