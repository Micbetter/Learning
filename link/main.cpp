#include <iostream>

using namespace std;

class MyLinkedList {
private:
    struct link{
        int value;
        struct link* next;
        struct link* prev;
    };
    int length = 0;
    struct link* phead = NULL;
    struct link* ptemp = NULL;
    struct link* ptemp2 = NULL;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= length) return -1;
        ptemp = phead;
        while (index--)
        {
            ptemp = ptemp->next;
        }
        return ptemp->value;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (phead == NULL) //链表为空
        {
            phead = new link();
            phead->value = val;
            phead->next = NULL;
            phead->prev = NULL;
        }
        else  //链表不为空
        {
            ptemp = new link();
            ptemp->value = val;
            ptemp->next = phead;
            ptemp->prev = NULL;

            phead->prev = ptemp;
            phead = ptemp;
        }
        ++length;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ptemp = phead;
        ptemp2 = new link();
        ptemp2->value = val;
        ptemp2->next = NULL;
        while (ptemp->next != NULL)
        {
            ptemp = ptemp->next;
        }
        ptemp->next = ptemp2;
        ptemp2->prev = ptemp;
        ++length;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= 0)
        {
            addAtHead(val);
        }
        else if(index < length)
        {
            ptemp = phead; //插入节点
            ptemp2 = new link();
            ptemp2->value = val;  //待插入节点
            while (index--)
            {
                ptemp = ptemp->next;
            }
            ptemp2->prev = ptemp->prev;
            ptemp2->next = ptemp;

            ptemp->prev->next = ptemp2;
            
            ptemp->prev = ptemp2;
            ++length;
        }
        else if(index == length)
        {
            addAtTail(val);
        }
        else
        {
            /* code */
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index > length-1) return;

        if(index == 0)
        {
            ptemp = phead;
            phead = phead->next;
            delete ptemp;
        }
        else if(index < length-1)
        {
            ptemp = phead;  //要删除的节点
            while (index--)
            {
                ptemp = ptemp->next;
            }
            ptemp->prev->next = ptemp->next;
            ptemp->next->prev = ptemp->prev;
            delete ptemp;
        }
        else if(index == length-1)
        {
            ptemp = phead;  //要删除的节点
            while (index--)
            {
                ptemp = ptemp->next;
            }
            ptemp->prev->next = NULL;
            delete ptemp;
        }
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
 //Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(1);
    obj->addAtHead(4);
    obj->addAtTail(5);
    obj->addAtIndex(2,3);
    obj->deleteAtIndex(2);
    
    return 0;
}
