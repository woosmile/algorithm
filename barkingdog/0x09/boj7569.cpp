#include <iostream>
#include <tuple>
#include <queue>
#include <math.h>

using namespace std;

int field[102][102][102];
int dist[102][102][102];

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int m, n, h;  // m: 가로, n: 세로, h: 높이

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue < tuple<int, int, int> > q;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)  // field[i][j][k];
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> field[i][j][k];
                if (field[i][j][k] == 1)
                    q.push({i, j, k});
                if (field[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int cx = get<2> (t);
            int cy = get<1> (t);
            int cz = get<0> (t);

            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                continue ;
            if (dist[nz][ny][nx] >= 0)
                continue ;
            dist[nz][ny][nx] = dist[cz][cy][cx] + 1;
            q.push({nz, ny, nx});
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dist[i][j][k] == -1)
                {
                    cout << -1;
                    return (0);
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans;

    return (0);
}