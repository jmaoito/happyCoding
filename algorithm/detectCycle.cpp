/********************
  LeetCode Linked List Cycle II 

  Given a linked list, return the node where the cycle begins. 
  If there is no cycle, return null.

  Tags: Linked List, Two Pointers

  Discussion:

  when fast met slow, slow moves s steps, fast moves 2s steps. assume the cycle
  length is r, then 2s = s + nr. (n is number of loops that fast already 
  completed, n>=1). then s = nr. 

  Assume the length of linked list is L, the begin of cycle is x, the distance
  from the cycle begin to the crossing node is a. then 
  x+a = s = nr = (n-1)r + r = (n-1)r + L - x
  L-(x+a) is the distance from cycle begin to crossing node. the distance from 
  head to cycle begin is equal to (n-1) clcye + distance from crossing node to
  cycle begin. 

  we set another pointer slow2 which starts from head and move one step once. 
  it will meet at the cycle begin.

  time complexity O(n), space complexity O(1)
**************************/
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
