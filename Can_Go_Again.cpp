#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e6 + 5;
long long int dis[N];
int main()
{
    long long int n, e;
    cin >> n >> e;
    vector<Edge> list;
    while (e--)
    {
      long long  int u, v, c;
        cin >> u >> v >> c;
        list.push_back(Edge(u, v, c));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e18;
    }
    int scr;
    cin>>scr;
    dis[scr] = 0;
    int t;
    cin >> t;
    while (t--)
    {
        long long int w;
        cin>>w;
        for (int i = 1; i <= n - 1; i++)
        {
            for (Edge ed : list)
            {
                int u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;
                if (dis[u] < 1e18 && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }
        bool cycle = false;
        for (Edge ed : list)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
        {

            if(dis[w]<1e18){
                cout << dis[w] << endl;
            }
            else{
                cout<<"Not Possible"<<endl;
            }
        }
    }
    return 0;
}