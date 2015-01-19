/*******************
  LeetCode Linked List Cycle

  Given a linked list, determine if it has a cycle in it.

  Follow up:
  Can you solve it without using extra space?

  Tags: Linked List, Two Pointers

  Discussion:

  Two pointers, one moves one step, the other moves two steps. if the two 
  pointers met together, the list has cycle.

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};
