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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head == NULL || head->next == NULL || left == right)
        {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pts = dummy;
        
        for(int i=1; i<left; i++)
        {
            pts = pts->next;
        }

        ListNode* curr = pts->next;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        int n = right-left+1;

        for(int i=1; i<=n; i++)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        pts->next->next = curr;
        pts->next = prev;

        return dummy->next;
    }
};