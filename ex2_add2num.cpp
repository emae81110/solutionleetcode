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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *templist = result;
        int carry = 0;

        while(l1 || l2  || carry){
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            ListNode *newnode = new ListNode(digit);
            templist->next = newnode;
            templist = templist->next;

            l1 = (l1==nullptr)?nullptr:(l1->next);
            l2 = (l2==nullptr)?nullptr:(l2->next);
        }
        
        ListNode *re = result->next;
        delete result;
        return re;
    }
};
