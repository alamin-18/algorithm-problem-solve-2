#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n+1][n+1];
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            adj[i][j] = 1e18;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
       if( adj[a][b] > c){
        adj[a][b]=c;
       }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    // for (int k = 0; k <n; k++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout<<adj[k][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    int q;
    cin >> q;
    while (q--)
    {
       int a,b;
       cin>>a>>b;
        if(adj[a][b] == 1e18)
                cout << "-1"<<endl;
        else
            cout << adj[a][b] << endl;

    }

    
    return 0;
}