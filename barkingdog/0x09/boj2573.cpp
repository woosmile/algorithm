#include <iostream>
#include <queue>
#include <utility>

#define X second
#define Y first

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int x, y, year;
int field[302][302];
int visit[302][302];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> y >> x;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> field[i][j];
        }
    }

    while (1)
    {
        year++;  // 빙산이 녹는 것에 대한 처리를 먼저 한 다음 BFS로 영역의 개수를 확인하는 순서여서 year를 증가시키고 시작함

        int zero[302][302] = {0};

        for (int i = 1; i < y - 1; i++)  // 상하좌우로 맞닿은 0의 개수 확인
        {
            for (int j = 1; j < x - 1; j++)
            {
                if (field[i][j] == 0)  // 이미 빙산이 다 녹아버린 0인 곳은 무시함
                    continue ;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = j + dx[dir];
                    int ny = i + dy[dir];

                    if (field[ny][nx] == 0)
                        zero[i][j]++;
                }
            }
        }

        for (int i = 1; i < y - 1; i++)  // 0의 개수만큼 감소 (단, 음수가 되지않도록 max 함수 사용)
        {
            for (int j = 1; j < x - 1; j++)
                field[i][j] = max(0, field[i][j] - zero[i][j]);
        }

        int piece = 0;  // 영역의 개수를 확인할 변수
        bool all_melt = true;  // 빙산이 전부 녹았는지 확인할 변수
        
        for (int i = 0; i < y; i++)
            fill(visit[i], visit[i] + x, 0);  // visit 배열 초기화

        for (int i = 1; i < y - 1; i++)
        {
            for (int j = 1; j < x - 1; j++)
            {
                if (field[i][j] == 0 || visit[i][j] == 1)
                    continue ;
                all_melt = false;  // 위 조건문에 걸리지 않았다는 것은 녹지않은 빙산이 있다는 의미임
                queue< pair<int, int> > q;
                visit[i][j] = 1;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (field[ny][nx] == 0 || visit[ny][nx] == 1)
                            continue ;
                        visit[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
                piece++;  // 큐가 비었다는 것은 인접한 영역의 탐색이 끝났음을 의미하므로 영역의 개수 증가
                if (piece >= 2)  // 2개의 영역으로 나뉘었다면 카운트 변수인 year 출력
                {
                    cout << year;
                    return (0);
                }
            }
        }

        if (all_melt == true)  // 빙산이 전부 녹을 때까지 영역이 2개로 나뉘지않았다면 0 출력
        {
            cout << 0;
            break ;
        }
    }

    return (0);
}
