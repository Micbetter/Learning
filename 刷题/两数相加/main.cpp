/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = nullptr;
        ListNode* head = nullptr;
        int bit = 0;
        int temp = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 == nullptr)
            {
                temp = l2->val + bit;
                bit = temp >= 10 ? 1 : 0;
                if(head == nullptr)
                {
                    head = node = new ListNode(temp % 10);
                }
                else
                {
                    node->next = new ListNode(temp % 10);
                    node = node->next;
                }
                l2 = l2->next;
            }
            else if(l2 == nullptr)
            {
                temp = l1->val + bit;
                bit = temp >= 10 ? 1 : 0;
                if(head == nullptr)
                {
                    head = node = new ListNode(temp % 10);
                }
                else
                {
                    node->next = new ListNode(temp % 10);
                    node = node->next;
                }
                l1 = l1->next;
            }
            else
            {
                temp = l1->val + l2->val + bit;
                bit = temp >= 10 ? 1 : 0;
                if(!head)
                {
                    head = node = new ListNode(temp % 10);
                }
                else
                {
                    node->next = new ListNode(temp % 10);
                    node = node->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if(temp >= 10)
        {
            node->next = new ListNode(1);
            node = node->next;
        }
        return head;
    }
};