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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == NULL && list2 == NULL) return NULL;
        vector<int> ans;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL)
        {
            ans.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            ans.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(ans.begin(),ans.end());

        ListNode* head = new ListNode(ans[0]);
        ListNode* temp = head;

        for(int i=1; i<ans.size(); i++)
        {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
