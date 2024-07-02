#include <iostream>
#include <utility>
#include <queue>

#define X second
#define Y first

using namespace std;

char board[102][102];
char visit[102][102];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    int size = 0;
    int res1 = 0, res2 = 0;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> board[i];
    }

    // BFS res1
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (visit[i][j] == 1)
                continue ;
            queue< pair<int, int> > q;
            visit[i][j] = 1;
            q.push({i, j});
            char color = board[i][j];  // 색상 값 확인을 위한 변수
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= size || ny >= size)
                        continue ;
                    if (board[ny][nx] != color || visit[ny][nx] == 1)  // 색상이 같지 않으면 큐에 넣지 않음
                        continue ;
                    visit[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
            res1++;
        }
    }

    // initial visit
    for (int i = 0; i < size; i++)
    {
        fill(visit[i], visit[i] + size, 0);  // 다음 BFS 진행을 위해 visit 초기화
    }

    // BFS res2
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (visit[i][j] == 1)
                continue ;
            queue< pair<int, int> > q;
            visit[i][j] = 1;
            q.push({i, j});
            char color = board[i][j];
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= size || ny >= size)
                        continue ;

                    if (color == 'B')  // 색상이 B 일 때는
                    {
                        if (board[ny][nx] != color || visit[ny][nx] == 1)  // B와 같은 값만 큐에 들어감
                            continue ;
                    }
                    else
                    {
                        if (board[ny][nx] == 'B' || visit[ny][nx] == 1)  // 적록색약은 R과 G를 같은 값으로 보기 때문에 B인 경우를 제외하고 R과 G인 경우 전부 큐에 들어감
                            continue ;
                    }

                    visit[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
            res2++;
        }
    }

    cout << res1 << " " << res2;

    return (0);
}