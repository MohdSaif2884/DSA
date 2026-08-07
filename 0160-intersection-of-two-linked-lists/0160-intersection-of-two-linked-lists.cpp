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
int linklength(ListNode *head){
int l =0;
while(head != NULL){
head = head->next;
l++;
}
return l;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int al = linklength(headA);
        int bl = linklength(headB);

        while(al > bl){
            al--;
            headA = headA->next;
        }

        while( bl > al){
            bl--;
            headB = headB->next;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
return headA;
        
    }
};