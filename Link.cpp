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
Node *insertSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *head2, *cur, *p, *q;

    head2 = head->next;
    head->next = nullptr;

    while (head2)
    {
        cur = head2;
        head2 = head2->next;

        for (p = nullptr, q = head; q && q->val < cur->val; p = q, q = q->next)
            ;
        if (q == head)
        {
            head = cur;
        }
        else
        {
            p->next = cur;
        }
        cur->next = q;
    }
    return head;
}
void sortLink(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    Node *tail = nullptr;
    for (Node *p = head; p->next != nullptr; p = p->next)
    {
        Node *cur = head;
        for (; cur->next != tail; cur = cur->next)
        {
            //大的沉底
            if (cur->val > cur->next->val)
            {
                int temp = cur->val;
                cur->val = cur->next->val;
                cur->next->val = temp;
            }
        }
        tail = cur;
    }
}
Node *getHead(Node *head)
{
    return nullptr;
}
void mergesort(Node *head)
{
    if (head->next)
    {
    }
}
int main()
{
    cout << "create link:\n";
    Node *head = create();
    print(head);

    cout << "insert sort:\n";
    head = insertSort(head);
    print(head);

    cout << "delete link node:\n";
    head = deleteNode(head, 2);
    print(head);

    cout << "insert node :\n";
    head = insertNode(head, 9, 3);
    print(head);

    cout << "insert tail:\n";
    head = insertTail(head, 10);
    print(head);

    cout << "reverse link:\n";
    head = reverseLink(head);
    print(head);

    cout << "sorted link:\n";
    sortLink(head);
    print(head);
    return 0;
}