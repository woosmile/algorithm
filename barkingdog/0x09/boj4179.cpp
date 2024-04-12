#include <utility>
#include <queue>
#include <iostream>
#include <string>

# define X first
# define Y second

using namespace std;

string board[1002];
int dist_f[1002][1002];
int dist_j[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue< pair<int, int> > f_q;
    queue< pair<int, int> > j_q;

    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
        cin >> board[i];

    for (int i = 0; i < row; i++)
    {
        fill(dist_f[i], dist_f[i] + col, -1);
        fill(dist_j[i], dist_j[i] + col, -1);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'F')
            {
                pair<int, int> p;
                p.X = i;
                p.Y = j;
                f_q.push(p);
                dist_f[i][j] = 0;
            }
            else if (board[i][j] == 'J')
            {
                pair<int, int> p;
                p.X = i;
                p.Y = j;
                j_q.push(p);
                dist_j[i][j] = 0;
            }
        }
    }
    while (!f_q.empty())
    {
        pair<int, int> cur = f_q.front();
        f_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= row || ny >= col)
                continue ;
            if (dist_f[nx][ny] >= 0 || board[nx][ny] == '#')
                continue ;
            dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;
            f_q.push({nx, ny});
        }
    }

    while (!j_q.empty())
    {
        pair<int, int> cur = j_q.front();
        j_q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= row || ny >= col)
            {
                cout << dist_j[cur.X][cur.Y] + 1;
                return (0);
            }
            if (dist_j[nx][ny] >= 0 || board[nx][ny] == '#')
                continue ;
            //불이 전파되지 않았다면 dist_f의 초기값 -1에서 변하지 않으므로 -1이 아닐 때의 조건을 추가해야 전파된 불이 없는 곳의 좌표를 j_q에 넣을 수 있음 
            if (dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_j[cur.X][cur.Y] + 1)
                continue ;
            dist_j[nx][ny] = dist_j[cur.X][cur.Y] + 1;
            j_q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return (0);
}