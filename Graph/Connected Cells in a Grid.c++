#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int connectedComp(vector<vector<int>> &v, int i, int j, int N, int M)
{
    if(i<0 || j<0 || i>=N || j>=M || v[i][j]!=1)
        return 0;
    
    if(v[i][j] == 1)
    {
        int count = 1;
        v[i][j] = 2;
        count += connectedComp(v, i+1, j, N, M) +
            connectedComp(v, i-1, j, N, M) +
            connectedComp(v, i, j+1, N, M) +
            connectedComp(v, i, j-1, N, M) +
            connectedComp(v, i+1, j+1, N, M) +
            connectedComp(v, i+1, j-1, N, M) +
            connectedComp(v, i-1, j-1, N, M) +
            connectedComp(v, i-1, j+1, N, M);
        return count;
    }
    return 1;
}

int main()
{
    int N, M;
    int count, max = 0;
    cin >> N >> M;
    
    vector<vector<int>> v(N, vector<int>(M));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>v[i][j];
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(v[i][j] == 1)
                count = connectedComp(v, i, j, N, M);
            max = count > max ? count : max;
        }
    }
    
    cout << max;
    return 0;
}
