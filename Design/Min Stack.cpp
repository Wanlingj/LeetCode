class MinStack {
public:
    /** initialize your data structure here. */
    class ListNode
    {
    public:
        int val;
        ListNode* prev_min;
        ListNode* next;
        ListNode (int val, ListNode* prev_min)
        {
            this->val = val;
            this->prev_min = prev_min;
            next = NULL;
        }
    } *head, *cur_min;
    
    /** initialize your data structure here. */
    MinStack() {
        head = cur_min = NULL;
    }
    
    void push(int x) {
        ListNode* temp = new ListNode (x, cur_min);
        temp->next = head;
        head = temp;
        cur_min = (cur_min == NULL || head->val < cur_min->val) ? head : cur_min;
    }
    
    void pop() {
        ListNode* temp = head->next;
        if (cur_min == head)
            cur_min = head->prev_min;
        delete head;
        head = temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return cur_min->val;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
