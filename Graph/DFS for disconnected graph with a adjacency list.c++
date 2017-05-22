#include <iostream>
#include <list>
using namespace std;
class graph
{
    public:
    int v;
    list<int> *adj;
    graph(int v)
    {
        this->v = v;
        this->adj = new list<int>[v];
    }
};

void addEdge(graph * g, int a, int b)
{
    g->adj[a].push_back(b);
    g->adj[b].push_back(a);
}

void printGraph(graph * g)
{
    list<int> :: iterator itr;
    cout << "no. of vertices in graph is " << g->v << endl;
    
    for(int i=0; i<g->v; i++)
    {
        cout << "we go from " << i << " to ";
        for(itr=g->adj[i].begin(); itr!=g->adj[i].end(); itr++)
        {
            cout << *itr << " ";
        }
        cout << endl;
    }
}

void dfsFn(graph * g, int s, bool visited[])
{
    cout << s << " ";
    visited[s] = true;
    
    list<int> :: iterator itr;
    
    for(itr=g->adj[s].begin(); itr!=g->adj[s].end(); itr++)
    {
        if(visited[*itr] == false)
        {
            dfsFn(g, *itr, visited);
        }
    }
    
}

void dfs(graph * g)
{
    bool visited[g->v] = {false};
    
    cout << "depth first search result is" << endl;
    
    for(int i=0; i<g->v; i++)
        if(visited[i] == false)
            dfsFn(g, i, visited);
}

int main()
{
    int v, e;
    cout << "enter the no. of vertices" << endl;
    cin >> v;
    
    graph * g = new graph(v);
    
    cout << "enter the no. of edges" << endl;
    cin >> e;
    
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        addEdge(g, a, b);
    }
    
    printGraph(g);
    
    dfs(g);
}
