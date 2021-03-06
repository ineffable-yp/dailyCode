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
//O(1)时间复杂度删除节点
Node *deleteNodeinO1(Node *head, Node *tobedel)
{
    if (head == tobedel)
        return head->next;
    if (tobedel->next == nullptr)
    {
        Node *tmp = head;
        while (tmp->next != tobedel)
            tmp = tmp->next;
        //尾部直接删除
        tmp->next = nullptr;
    }
    else
    {
        tobedel->val = tobedel->next->val;
        tobedel->next = tobedel->next->next;
    }
    return head;
}
//删除第k个节点，双指针法
Node *deleteKNode(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    int i = 0;
    Node *first, *second;
    first = head;
    while (i < k && first)
    {
        second = first;
        first = first->next;
        ++i;
    }
    second->next = first->next;
    delete first;
    return head;
}
//删除重复节点(有序)
Node *deleteDupNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *cur, *prev;
    cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
        prev = cur->next;
        if (prev->val == cur->val)
        {
            cur->next = prev->next;
            delete prev;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}
//按值删除指定节点
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
//链表反转
Node *reverseLink(Node *head)
{
    Node *prev, *pCur;

    pCur = head;
    //尾部节点
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
//链表是否有环
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
//插入排序
Node *insertSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *head2, *cur, *p, *q;

    head2 = head->next;
    //孤立头部，已插入
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
//冒泡排序
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
//合并两条子链
Node *merge(Node *head, Node *head2)
{
    Node *curHead = nullptr;
    Node *p = new Node(-1);
    curHead = p;
    while (head && head2)
    {
        if (head->val > head2->val)
        {
            p->next = head2;
            head2 = head2->next;
            p = p->next;
        }
        else
        {
            p->next = head;
            head = head->next;
            p = p->next;
        }
    }
    if (head != nullptr)
        p->next = head;
    else
        p->next = head2;
    return curHead->next;
}
//归并排序
Node *mergesort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *fast, *slow, *prev;
    fast = head;
    slow = head;
    prev = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    //寻找链中间节点，分开
    prev->next = nullptr;
    return merge(mergesort(head), mergesort(slow));
}
int main()
{
    cout << "create link:\n";
    Node *head = create();
    print(head);

    cout << "mergeSort:\n";
    head = mergesort(head);
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

    cout << "delete k node:\n";
    head = deleteKNode(head, 3);
    print(head);

    cout << "delete dup node:\n";
    head = deleteDupNode(head);
    print(head);
    return 0;
}