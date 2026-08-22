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
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL)
        {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = NULL;
        second = reverse(second);

        while(second != NULL)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second;
            second = second->next;
            first->next = temp2;
            temp2->next = temp1;
            first = first->next->next;
        }
    }
};
