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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL)
        {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        head = reverse(head);
        ListNode* prev = NULL;
        ListNode* temp = head;

        for(int i=1; i<n; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if(prev == NULL)
        {
            head = temp->next;
            delete temp;
        }
        else
        {
            prev->next = temp->next;
            temp->next = NULL;
        }
        
        return reverse(head);
    }
};
