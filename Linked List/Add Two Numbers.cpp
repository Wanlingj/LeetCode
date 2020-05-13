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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            if(l1) {
                carry+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry+=l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry%10);
            carry /= 10;
            p = p->next;
        }
        return dummy->next;
    
    }
};


//Another faster solution
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         if (l1 == NULL && l2 ==  NULL) return NULL;

        int carrier = 0;
        int val1 = 0, val2 = 0;

        val1 = l1 ? l1->val : 0;
        val2 = l2 ? l2->val : 0;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        ListNode* head = new ListNode( (val1 + val2) % 10);
        ListNode* nodePrev = head;

        if (val1 + val2 >= 10) carrier = 1;
        else carrier = 0;

        while(l1 || l2 || carrier)
        {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            ListNode* nodeCurr = new ListNode( (val1 + val2 + carrier)%10 );
            nodePrev->next = nodeCurr;
            nodePrev = nodePrev->next;

            if (val1 + val2 + carrier >= 10) carrier = 1;
            else carrier = 0;
        }

        return head;
    }
};
