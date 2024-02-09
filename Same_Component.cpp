#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
char mat[N][N];
int vis[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return !vis[x][y] && mat[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if (valid(ci, cj) == true && mat[ci][cj] == '.' && vis[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    int a, b;
    int c, d;
    cin >> a >> b;
    cin >> c >> d;
    dfs(a, b);

    if (vis[c][d])
    {

        cout <<"YES"<< " ";
    }
    else
    {
        cout <<"NO"<< " ";
    }

    return 0;
}