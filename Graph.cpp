#include <iostream>

using namespace std;

class Node
{
public:
    Node(int data);
    Node(const Node &node);

public:
    int m_data;
    bool m_bVisited;
};
class Edge
{
public:
    int m_iNodeIndexA;
    int m_iNodeIndexB;
    int m_iWeight;
    bool m_bSelected;
};
class Graph
{
};
int main()
{
    return 0;
}