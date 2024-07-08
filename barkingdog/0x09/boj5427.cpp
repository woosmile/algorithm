#include <queue>
#include <utility>
#include <iostream>

#define X second
#define Y first

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

char field[1002][1002];
int fire[1002][1002];
int human[1002][1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, h;

    cin >> n;

    for (int c = 0; c < n; c++)
    {
        queue< pair<int, int> > q;
        pair<int, int> human_pos;
        bool escape = false;

        cin >> w >> h;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> field[i][j];
                
                if (field[i][j] == '*')
                {
                    fire[i][j] = 1;
                    q.push({i, j});
                }
                if (field[i][j] == '@')
                {
                    human[i][j] = 1;
                    human_pos.X = j;   // 하나의 큐로 처리하고 싶어서 불의 BFS가 끝난 후 큐에 넣을 pair 변수에 사람의 위치를 저장함
                    human_pos.Y = i;
                    // human_pos = {i, j};
                }
            }
        }

        while (!q.empty())  // 불 좌표의 BFS 먼저 진행
        {
            pair<int, int> cur = q.front();
            q.pop();
            
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                    continue ;
                if (field[ny][nx] == '#' || fire[ny][nx] > 0)
                    continue ;
                fire[ny][nx] = fire[cur.Y][cur.X] + 1;
                q.push({ny, nx});
            }
        }

        q.push(human_pos);  // 위에서 저장한 사람의 좌표를 큐에 넣음

        while (!q.empty() && escape == false)
        {
            pair<int, int> cur = q.front();
            q.pop();
            
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h)  // 위치를 벗어났다는 것은 탈출을 했음을 의미함
                {
                    cout << human[cur.Y][cur.X] << '\n';  // 탈출한 좌표값(도착하기까지 걸린 시간 즉, 거리) 출력
                    escape = true;  // 탈출했으면 끝이므로 더이상 BFS를 진행하지 않아야 함(탈출할 수 있는 좌표가 여러 경우라면 여러번 출력되는 것을 막음)
                    break ;
                }
                if (field[ny][nx] == '#' || human[ny][nx] > 0)
                    continue ;
                if (fire[ny][nx] != 0 && human[cur.Y][cur.X] + 1 >= fire[ny][nx])  // 이동하려는 곳이 이미 불이 지나간 곳이라면 그 좌표로는 이동할 수 없음
                    continue ;

                human[ny][nx] = human[cur.Y][cur.X] + 1;
                q.push({ny, nx});
            }
        }

        for (int i = 0; i < h; i++)  // 다음 테스트 케이스를 위한 초기화
        {
            fill(field[i], field[i] + w, 0);
            fill(fire[i], fire[i] + w, 0);
            fill(human[i], human[i] + w, 0);
        }

        if (escape == false)  // 탈출하지 못했다면 아래 문구 출력
            cout << "IMPOSSIBLE" << '\n';
    }

    return (0);
}