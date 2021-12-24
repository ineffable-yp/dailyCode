/*
 * @brief description:        图的欧拉路径搜索
 * @author:                     yinpan
 * @date:                      2021-12-24 16:32
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* Edge : 边结构
* v,w: vertex 顶点(起末) 
*/
struct Edge
{
    int v, w;
    Edge(int v = -1, int w = -1) : v(v), w(w)
    {
    }
};

class Graph
{
private:
    int vcount, ecount;       //记录顶点总数，边总数
    bool IsDAG;               //标记是否有向图
    vector<vector<bool>> adj; //邻接矩阵数组
public:
    Graph(int V, bool di = false) : adj(V), vcount(V), IsDAG(di)
    {
        for (int i = 0; i < V; i++)
            adj[i].assign(V, false); // V * V 临接矩阵的大小
    }
    //~Graph();
    int V() const { return vcount; }

    int E() const { return ecount; }

    bool directed() const { return IsDAG; }

    int insert(Edge e)
    {
        int v = e.v, w = e.w;
        if (adj[v][w] == false)
            ecount++;
        adj[v][w] = true; // v-w 做标记
        if (!IsDAG)
            adj[w][v] = true; //无向图中 w-v 也做标记
        return 1;
    }

    int remove(Edge e)
    {
        int v = e.v, w = e.w;
        if (adj[v][w] == true)
            ecount--;
        adj[v][w] = false; // 去 连接
        if (!IsDAG)
            adj[w][v] = false;
        return 1;
    }

    //v-w是否有边相连
    bool edge(int v, int w) const { return adj[v][w]; }

    class adjIterator;
    friend class adjIterator;
};

class Graph::adjIterator //临接矩阵表示的迭代器
{
private:
    const Graph &G;
    int i, v;

public:
    adjIterator(const Graph &G, int v) : G(G), v(v), i(-1)
    {
    }

    int begin()
    {
        i = -1;
        return next();
    }

    int next()
    {
        for (i++; i < G.V(); i++)
            if (G.adj[v][i] == true)
                return i; //adj[v][0..v-1] 记录着 v 到 0..v 各点是否相连
        return -1;        //没有找到
    }

    int end()
    {
        return i >= G.V();
    }
};

//描述图各顶点的度数的类
class Degree
{
private:
    const Graph &G;
    vector<int> degree;

public:
    Degree(const Graph &G) : G(G), degree(G.V(), 0)
    {
        for (int v = 0; v < G.V(); v++)
        {
            Graph::adjIterator ite(G, v); //获取顶点v的遍历器
            for (int w = ite.begin(); !ite.end(); w = ite.next())
                degree[v]++; //统计顶点的度数
        }
    }
    int operator[](int v) const
    {
        return degree[v];
    }
};

class epath
{
private:
    Graph G;
    int v, w;
    bool found;

    stack<int> S;
    int tour(int v);

public:
    epath(const Graph &G, int v, int w) : G(G), v(v), w(w)
    {
        //查找欧拉路径基于
        //1.它是连通的，而且所有顶点都有偶数度数
        //2.它是连通的，而且只有两个顶点有奇数度数（首尾）

        Degree deg(G);
        int t = deg[v] + deg[w];
        if (t % 2 != 0)
        {
            found = false;
            return;
        } //顶点数要偶数, 或两个奇数

        //其他路径点 度数都是偶数
        for (t = 0; t < G.V(); t++)
            if ((t != v) && (t != w))
            {
                if (deg[t] % 2 != 0)
                {
                    found = false;
                    return;
                }
            }
        found = true;
    }
    bool exist() const { return found; }

    void show(); //输出路径
};

int epath::tour(int v)
{
    while (true)
    {
        Graph::adjIterator ite(G, v);
        int w = ite.begin();
        if (ite.end())
            break;
        S.push(v);
        G.remove(Edge(v, w));
        v = w;
    }
    return v; //回到起点？回路 : 通路
}

void epath::show()
{
    if (!found)
        return;
    while (tour(v) == v && !S.empty())
    {
        v = S.top();
        S.pop();
        cout << " - " << v;
    }
    cout << endl;
}

int main()
{
    Graph g(7, false);

    g.insert(Edge(0, 1));
    g.insert(Edge(0, 2));
    g.insert(Edge(0, 5));
    g.insert(Edge(0, 6));

    g.insert(Edge(1, 2));
    g.insert(Edge(2, 3));
    g.insert(Edge(2, 4));
    g.insert(Edge(3, 4));
    g.insert(Edge(4, 5));
    g.insert(Edge(4, 6));

    epath sp(g, 1, 6);          //顶点1到6的欧拉路径
    cout << sp.exist() << endl; //输出结果 0 或 1
    sp.show();

    return 0;
}