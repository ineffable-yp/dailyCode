#include <iostream>

using namespace std;

//链表节点
struct Node
{
    int val;
    Node *next;
    Node(int a) : val(a), next(nullptr) {}
};

void print(Node *head)
{
    Node *temp;
    if (head == nullptr)
        return;
    temp = head;
    cout << "val: ";
    while (temp)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}
Node *create()
{
    Node *pHead, *pCur, *pNew;
    int data;
    pHead = new Node(0);
    pCur = pHead;
    cin >> data;
    //尾部插入新的元素
    while (-1 != data)
    {
        pNew = new Node(data);
        pCur->next = pNew;
        pCur = pNew;
        cin >> data;
    }
    return pHead;
}
Node *insertTail(Node *head, int data)
{
    Node *pCur, *pNew;
    pNew = new Node(data);
    pCur = head;
    while (pCur->next)
        pCur = pCur->next;
    pCur->next = pNew;
    return head;
}
Node *insertNode(Node *head, int data, int needData)
{
    Node *pCur, *pNew;

    pNew = new Node(data);
    //寻找尾部
    pCur = head;
    while (pCur)
    {
        if (pCur->val == needData)
        {
            pNew->next = pCur->next;
            pCur->next = pNew;
            break;
        }
        //避免空指针
        if (pCur->next == nullptr)
            break;
        pCur = pCur->next;
    }
    if (pCur->next == nullptr)
    {
        cout << "no " << pNew->val << endl;
        pCur->next = pNew;
    }
    return head;
}
Node *deleteNode(Node *head, int data)
{
    if (head == nullptr)
        return nullptr;
    Node *cur, *prev;
    prev = head;
    cur = prev->next;
    while (cur)
    {
        if (cur->val == data)
            break;
        //指针后移一位
        prev = cur;
        cur = cur->next;
    }
    if (cur == nullptr)
        cout << "no node's val is " << data << endl;
    else
    {
        prev->next = cur->next;
        delete cur;
    }
    return head;
}
Node *reverseLink(Node *head)
{
    Node *prev, *pCur;

    pCur = head;
    prev = nullptr;
    while (pCur)
    {
        Node *pNext = pCur->next;
        pCur->next = prev;

        prev = pCur;
        pCur = pNext;
    }
    return prev;
}
bool isCircleLink(Node *head)
{
    Node *fast, *slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
int main()
{
    Node *head = create();
    print(head);

    head = deleteNode(head, 2);
    print(head);

    head = insertNode(head, 9, 3);
    print(head);

    head = insertTail(head, 10);
    print(head);

    head = reverseLink(head);
    print(head);
    return 0;
}