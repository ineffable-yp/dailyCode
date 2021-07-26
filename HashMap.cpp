#include <iostream>

using namespace std;

typedef struct HashNode
{
    int val;
    HashNode *next;
} HashNode;

class HashMap
{
public:
    HashMap();
    HashMap(const int &);
    ~HashMap();
    void insert(const int &);
    bool find(const int &);
    bool deleteKey(const int &);
    bool isEmpty();
    int size();
    void clear();
    void print();

private:
    int _size;
    int key_num;
    HashNode *buffer;
};

//构造为哈希表分配空间
HashMap::HashMap()
{
    key_num = 15;
    _size = 0;
    buffer = new HashNode[key_num];
    for (int i = 0; i < key_num; i++)
    {
        buffer[i].next = nullptr;
    }
}

HashMap::HashMap(const int &keyNum) : key_num(keyNum), _size(0)
{
    buffer = new HashNode[key_num];
    for (int i = 0; i < key_num; i++)
    {
        buffer[i].next = nullptr;
    }
}

bool HashMap::isEmpty()
{
    return _size > 0 ? true : false;
}

int HashMap::size()
{
    return _size;
}
bool HashMap::find(const int &key)
{
    int idx = key % key_num; //找到桶号
    HashNode *cur = buffer[idx].next;
    while (cur)
    {
        if (cur->val == key)
            return true;
        cur = cur->next;
    }
    return false;
}
bool HashMap::deleteKey(const int &key)
{
    int idx = key % key_num;
    HashNode *cur = &buffer[idx];
    while (cur)
    {
        if (cur->next && cur->next->val == key)
        {
            HashNode *t = cur->next;
            cur->next = t->next;
            delete t;
            _size--;
        }
        else
            cur = cur->next;
    }
    return true;
}
void HashMap::insert(const int &key)
{
    HashNode *newNode = new HashNode;
    newNode->val = key;
    newNode->next = nullptr;

    HashNode *cur = buffer[newNode->val % key_num].next;
    buffer[newNode->val % key_num].next = newNode;
    newNode->next = cur;
    _size++;
}
void HashMap::clear()
{
    for (int i = 0; i < key_num; i++)
    {
        HashNode *cur = buffer[i].next;
        while (cur)
        {
            //指针后移
            HashNode *t = cur->next;
            buffer[i].next = t;
            delete cur;
            cur = t;
        }
    }
    _size = 0;
}
void HashMap::print()
{
    for (int i = 0; i < key_num; i++)
    {
        cout << "[" << i << "]:->";
        HashNode *cur = buffer[i].next;
        while (cur)
        {
            cout << cur->val;
            cur = cur->next;
            if (cur)
                cout << "->";
        }
        cout << endl;
    }
}
HashMap::~HashMap()
{
    clear();
    delete[] buffer;
}
int main()
{
    HashMap hashmap(15);
    for (int i = 0; i < 100; i++)
    {
        hashmap.insert(i);
    }
    hashmap.print();
    cout << "size= " << hashmap.size() << endl;
    return 0;
}