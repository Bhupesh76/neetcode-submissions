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
    ListNode* reverse(ListNode* head,int left,int right)
    {
        if(head == NULL || head->next == NULL || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pos = dummy;

        for(int i=1; i<left; i++)
        {
            pos = pos->next;
        }

        int n = right-left+1;

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        ListNode* curr = pos->next;

        for(int i=1; i<=n; i++)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        pos->next->next = curr;
        pos->next = prev;

        return dummy->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            n++;
        }

        for(int i=1; i+k-1<=n; i+=k)
        {
            head = reverse(head,i,i+k-1);
        }
        return head;
    }
};
