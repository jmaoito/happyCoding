/****************
  LeetCode Copy List with Random Pointer

  A linked list is given such that each node contains an additional random 
  pointer which could point to any node in the list or null.

  Return a deep copy of the list.

  Discussion:
  Scan two times. in the first time, duplicate all the nodes in the list to be
  the ->next of the existing node. in the second scan, assign the new node's 
  random pointer to the ->next of the original random pointer.
  Finally, spin the new list off

  time complexity O(n), space complexity O(1)
****************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode* cur = head; cur != nullptr; ) {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        for (RandomListNode* cur = head; cur != nullptr; ) {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // spin off the new link list
        RandomListNode dummy(-1);
        for (RandomListNode* cur = head, *new_cur = &dummy;
               cur != nullptr; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
