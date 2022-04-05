//返回链表
#include<vector>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};



class Solution {
public:
    //双指针迭代法
    ListNode* reverse(ListNode* head) {
        ListNode* current_node = head;
        ListNode* last_node = nullptr;
        while (current_node != nullptr)
        {
            ListNode* next_node = head->next;
            current_node->next = last_node;
            last_node = current_node;
            current_node = next_node;
        }
        return last_node;
    }

    //使用栈
    ListNode* reverse(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* node = head;
        while (node != nullptr)
        {
            stk.push(node);
            node = node->next;
        }
        while (!stk.empty())
        {
            node = stk.top();
            stk.pop();
            node->next = stk.top();
        }
        
        
    }

};
