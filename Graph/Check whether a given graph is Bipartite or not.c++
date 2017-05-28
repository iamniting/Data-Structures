#include <iostream>
#include <list>
using namespace std;

bool isBipartite = true;

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

void is_bipartite(graph * g, int s, bool visited[], int color[])
{
    list<int> :: iterator itr;
    
    if(isBipartite)
    {
        visited[s] = true;
        for(itr=g->adj[s].begin(); itr!=g->adj[s].end(); itr++)
        {
            if(visited[*itr] == false)
            {
                if(color[s] == 1)
                {
                    color[*itr] = 0;
                }
                else
                {
                    color[*itr] = 1;
                }
                is_bipartite(g, *itr, visited, color);
            }
            else
            {
                if(color[s] == color[*itr])
                isBipartite = false;
            }
        }
    }
}

void bipartite(graph * g)
{
    bool visited[g->v];
    int color[g->v];
    
    for(int i=0; i<g->v; i++)
    {
        visited[i] = false;
        color[i] = -1;
    }
    
    color[0] = 1;
    
    is_bipartite(g, 0, visited, color);
}

int main()
{
    int v, e;
    //cout << "enter the no. of vertices" << endl;
    cin >> v;
    
    graph * g = new graph(v);
    
    //cout << "enter the no. of edges" << endl;
    cin >> e;
    
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        addEdge(g, a, b);
    }
    
    //printGraph(g);
    
    bipartite(g);
    
    if(isBipartite)
        cout << "Yes";
    else
        cout << "No";
        
    return 0;
}
