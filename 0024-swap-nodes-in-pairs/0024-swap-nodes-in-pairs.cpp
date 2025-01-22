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

    ListNode* reverseKGroups(ListNode* head, int k)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward;

        int count =0;

        while(count<k && curr!=NULL)
        {
            forward = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //now prev is the head of k [2] group
        //forward is pointing on next group

        //head is the last node

        if(forward!=NULL)
        {
            head->next = reverseKGroups(forward,k);
        }

        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        return reverseKGroups(head,2);
       
    }
};