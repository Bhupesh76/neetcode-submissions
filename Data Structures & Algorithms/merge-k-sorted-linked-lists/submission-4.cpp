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
    ListNode* mergetwo(ListNode* head1,ListNode* head2)
    {
        if(head1 == NULL)
        {
            return head2;
        }
        else if(head2 == NULL)
        {
            return head1;
        }

        if(head1->val <= head2->val)
        {
            head1->next = mergetwo(head1->next,head2);
            return head1;
        }
        else 
        {
            head2->next = mergetwo(head1,head2->next);
            return head2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0) return NULL;
        
        for(int interval = 1; interval < lists.size(); interval *= 2)
        {
            for(int i=0; i+interval<lists.size(); i += interval*2)
            {
                lists[i] = mergetwo(lists[i],lists[i+interval]);
            }
        }

        return lists[0];    
    }
};
