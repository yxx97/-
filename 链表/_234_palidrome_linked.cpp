 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        if(head->next->next == nullptr) return head->val == head->next->val;

        ListNode* mid = findmind(head);
        ListNode * rhead = rever(mid->next);
        ListNode * lhead = head;
        while(rhead){
            if(lhead->val != rhead->val) return false;
            rhead = rhead->next;
            lhead = lhead->next;
        }
        return true;


    }
    // 找链表的中心点
    ListNode * findmind(ListNode* head){
        ListNode * slow = head;
        ListNode *fast  = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    // 双指针反转链表
    ListNode * rever(ListNode * head){
        ListNode * newhead = nullptr;
        while(head){
            ListNode*temp = head->next;
            head->next = newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }
};