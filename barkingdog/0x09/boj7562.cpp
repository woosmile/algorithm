#include <queue>
#include <utility>
#include <iostream>

#define X second
#define Y first

using namespace std;

int dist[302][302];

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};  // 나이트의 이동 좌표
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(void)
{
    int tc;

    cin >> tc;

    for (int cycle = 0; cycle < tc; cycle++)
    {
        int size, start_x, start_y, end_x, end_y;

        cin >> size >> start_x >> start_y >> end_x >> end_y;

        dist[start_y][start_x] = 1;  // 시작지점을 다시 방문하지 않게 하려고 1로 할당

        queue< pair<int, int> > q;
        q.push({start_y, start_x});
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)  // 나이트는 8방향으로 이동함
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= size || ny < 0 || ny >= size)  // 범위 확인
                    continue ;
                if (dist[ny][nx] > 0)  // 방문한 적이 있는지 확인
                    continue ;
                dist[ny][nx] = dist[cur.Y][cur.X] + 1;
                q.push({ny, nx});
            }
        }

        cout << dist[end_y][end_x] - 1 << "\n";   // 도착 지점까지 도달했을 때의 값(거리)을 출력 (27번 째 줄에서 값을 1에서 증가시켰으므로 출력할 때는 -1)

        for (int i = 0; i < size; i++)  // 다음 테스트를 위해 배열 초기화
        {
            fill(dist[i], dist[i] + size, 0);
        }
    }

    return (0);
}