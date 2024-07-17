#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define X second
#define Y first

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int board[102][102];
int vis[102][102];
int dist[102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue< pair<int, int> > q;
    int cnt = 0;  // 영역 별로 다른 숫자로 구분하기 위한 변수

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] != 0 || board[i][j] != 1)
                continue ;
            cnt++;  // 1, 2, 3 ... 순으로 영역을 구분지음
            vis[i][j] = 1;
            board[i][j] = cnt;
            q.push({i, j});
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue ;
                    if (vis[ny][nx] != 0 || board[ny][nx] != 1)
                        continue ;
                    board[ny][nx] = cnt;
                    vis[ny][nx] = 1;
                    q.push({ny, nx});
                    
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + n, -1);
    }

    int ans = 99999;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue ;
            q.push({i, j});
            dist[i][j] = 0;  // 거리 측정을 위해서 0부터 시작
            bool escape = false;  // BFS 탈출 변수
            while (!q.empty() && escape != true)
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)  // OOB(Out of Bound) 확인
                        continue ;
                    if (dist[ny][nx] >= 0 || board[i][j] == board[ny][nx])  // 빈 공간(바다) 또는 같은 영역(섬) 안이라면 넘어감
                        continue ;
                    if (board[ny][nx] != 0 && board[i][j] != board[ny][nx])  // 빈 공간(바다)이 아니면서 다른 영역(섬)이라면 다른 영역(섬)에 닿았음
                    {
                        ans = min(ans, dist[cur.Y][cur.X]);  // 다른 섬에 닿았을 때까지 측정한 거리가 최소값인지 확인
                        while (!q.empty())  // 한 영역에서 다른 영역에 닿았으므로 큐를 비우고 다음 BFS 진행
                            q.pop();
                        escape = true;  // BFS while문 탈출
                        break ;
                    }
                    dist[ny][nx] = dist[cur.Y][cur.X] + 1;  // 다른 영역에 닿을 때까지 거리 +1
                    q.push({ny, nx});
                }
            }
            for (int i = 0; i < n; i++)  // dist 초기화
            {
                fill(dist[i], dist[i] + n, -1);
            }
        }
    }

    cout << ans;

    return (0);
}