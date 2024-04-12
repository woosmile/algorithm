#include <iostream>
#include <utility>
#include <queue>

#define X second
#define Y first

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool board[502][502];
    bool visit[502][502];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};


    int x = 0, y = 0;
    int mx = 0, cnt = 0;

    cin >> y;
    cin >> x;
    
    for (int y_idx = 0; y_idx < y; y_idx++)
    {
        for (int x_idx = 0; x_idx < x; x_idx++)
        {
            cin >> board[y_idx][x_idx];
            visit[y_idx][x_idx] = false;
        }
    }

    for (int y_idx = 0; y_idx < y; y_idx++)
    {
        for (int x_idx = 0; x_idx < x; x_idx++)
        {
            queue< pair <int, int> > q;
            if (board[y_idx][x_idx] == true && visit[y_idx][x_idx] == false)
            {
                q.push({y_idx, x_idx});
                visit[y_idx][x_idx] = true;
                cnt++;
                int mx_temp = 0;
                while (q.empty() == 0)
                {
                    mx_temp++;
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= x || ny < 0 || ny >= y)
                            continue ;
                        if (visit[ny][nx] == true || board[ny][nx] == false)
                            continue ;
                        visit[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
                mx = max(mx, mx_temp);
            }
        }
    }

    cout << cnt << '\n' << mx << '\n';

    return (0);
}