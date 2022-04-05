/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        while (l1 && l2)    //当l1,l2均非空时
        {
            if(l1->val <= l2->val)
            {
                l1->next = mergeTwoLists(l1->next,l2);
                return l1;
            }
            else
            {
                l2->next = mergeTwoLists(l1,l2->next);
                return l2;
            }
            
        }
        return nullptr;
        
    }
};