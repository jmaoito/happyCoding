/**********  
  LeetCode Sort List

  Sort a linked list in O(nlogn) time using constant space complexity

Discussion:
  for singly-linked list, merge sort is better
  for double-linked list, quick sort is better

************/

/**
 * Defination for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *merge(ListNode* l1, ListNode* l2, ListNode* h){
        ListNode* l=h;
        while(l1||l2){
            if(!l1 || l2 && l1->val>l2->val){
                l->next=l2;
                l2=l2->next;
            } else {
                l->next=l1;
                l1=l1->next;
            }
            l=l->next;
        }
        return l;
    }
/*    ListNode *merge(ListNode* l1, ListNode* l2, ListNode* h){
        ListNode* l=h;
        while(l1||l2){
            if(!l1){
                l->next=l2;
                l2=l2->next;
            }
            else if(!l2){
                l->next=l1;
                l1=l1->next;
            }
            else if(l1->val<l2->val){
                l->next=l1;
                l1=l1->next;
            }
            else {
                l->next=l2;
                l2=l2->next;
            }
            l=l->next;
        }
        return l;
    }*/
    
    ListNode* split(ListNode* h, int len){
        for(int i=1;i<len&&h!=NULL;i++){
            h=h->next;
        }
        if(!h) return NULL;
        ListNode* t=h->next;
        h->next=NULL;
        return t;
    }
    
    ListNode *sortList(ListNode *head) {
        ListNode n(0);
        n.next=head;
        int listlen=0;
        while(head)
        {
            listlen++;
            head=head->next;
        }
        for(int len=1;len<listlen;len*=2)
        {
            ListNode* t=n.next,*l1,*l2;
            ListNode* h=&n;
            while(t!=NULL)
            {
                l1=t;
                l2=split(t,len);
                t=split(l2,len);
                ListNode* tail=merge(l1,l2,h);
                tail->next=t;
            }
        }
        return n.next;
    }
};
