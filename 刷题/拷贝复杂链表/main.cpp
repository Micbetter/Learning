//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。https://leetcode-cn.com/leetbook/read/illustration-of-algorithm/9p0yy1/
//https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png

#include<unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    //建立一个map来存储原来链表与新建链表的对应关系
    unordered_map<Node*,Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(!cachedNode.count(head))   //只有没创建过才创新的，如果被创建过则直接返回
        {
            Node* node = new Node(head->val);
            cachedNode[head] = node;
            node->next = copyRandomList(head->next);        //都会新建
            node->random = copyRandomList(head->random);    ///可能会新建，可能有已
        }
        return cachedNode[head];

    }
};