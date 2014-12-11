/***********************
  LeetCode Intersection of Two Linked Lists

  Write a program to find the node at which the intersection of two singly linked lists begins.

  For example, the following two linked lists:

   A:          a1 → a2
                       ↘
                         c1 → c2 → c3
                       ↗            
   B:     b1 → b2 → b3
   begin to intersect at node c1.

   Notes:

   If the two linked lists have no intersection at all, return null.
   The linked lists must retain their original structure after the function returns.
   You may assume there are no cycles anywhere in the entire linked structure.
   Your code should preferably run in O(n) time and use only O(1) memory.

   Discussion:

   Method 1(Simply use two loops)
   Use 2 nested for loops. Outer loop will be for each node of the 1st list and inner loop will be for 2nd list. 
   In the inner loop, check if any of nodes of 2nd list is same as the current node of first linked list. 
   Time complexity of this method will be O(mn) where m and n are the number of nodes in two lists.

   Method 2 (Mark Visited Nodes)
   This solution requires modifications to basic linked list data structure. 
   Have a visited flag with each node. Traverse the first linked list and keep marking visited nodes. 
   Now traverse second linked list, If you see a visited node again then there is an intersection point, 
   return the intersecting node. This solution works in O(m+n) but requires additional information with 
   each node. A variation of this solution that doesn’t require modification to basic data structure can 
   be implemented using hash. Traverse the first linked list and store the addresses of visited nodes in 
   a hash. Now traverse the second linked list and if you see an address that already exists in hash then 
   return the intersecting node.

   Method 3(Using difference of node counts)
   1) Get count of the nodes in first list, let count be c1.
   2) Get count of the nodes in second list, let count be c2.
   3) Get the difference of counts d = abs(c1 – c2)
   4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the 
      lists have equal no of nodes.
   5) Then we can traverse both the lists in parallel till we come across a common node. 
      (Note that getting a common node is done by comparing the address of the nodes)

*****************************/

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
    size_t getListSize(ListNode *head) const {
        size_t size = 0;
        if (head == NULL) return 0;
        ListNode *next = head->next;
        while (next) {
            size ++;
            next = next->next;
        }
        return ++size;
    }
    
    ListNode *_getIntersectionNode(const size_t d, ListNode *head1, ListNode *head2) {
        ListNode *current1 = head1;
        ListNode *current2 = head2;
        
       for (int i=0; i<d; ++i) {
            if (current1->next) {
                current1 = current1->next;
            }
        }
        while (current1 && current2) {
            if (current1 == current2) return current1;
            current1 = current1->next;
            current2 = current2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t s1 = getListSize(headA);
        size_t s2 = getListSize(headB);
        
        if (s1 > s2) {
            size_t d = s1 - s2;
            return _getIntersectionNode(d, headA, headB);
        }
        else {
            size_t d = s2 - s1;
            return _getIntersectionNode(d, headB, headA);
        }
    }
};
