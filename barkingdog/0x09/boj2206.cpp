#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

char field[1002][1002];  // 입력을 1110 이런식으로 띄어쓰기 없이 받는다면 char로 받기
int dist[1002][1002][2];  // 거리를 구할 2차원 배열을 2개 만듬 (벽을 부수지 않는 경우, 벽을 하나만 부수는 경우)

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x_input, y_input;

    cin >> y_input >> x_input;

    for (int i = 0; i < y_input; i++)
    {
        for (int j = 0; j < x_input; j++)
        {
            cin >> field[i][j];
        }
    }

    dist[0][0][0] = dist[0][0][1] = 1;  // 시작 지점도 카운트에 포함되므로 1로 시작

    queue< tuple<int, int, int> > q;
    q.push({0, 0, 0});

    while (!q.empty())
    {
        int y, x, broken;
        tie(y, x, broken) = q.front();  // tie를 사용하면 pair, tuple로 묶인 원소를 꺼내 쓰기 용이함
        if (y == y_input - 1 && x == x_input - 1)  // 도착 지점에 도달했다면 도착 지점의 값(거리) 출력
        {
            cout << dist[y][x][broken];
            return (0);
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= x_input || ny < 0 || ny >= y_input)  // 범위 체크
                continue ;
            if (field[ny][nx] == '0' && dist[ny][nx][broken] == 0)  // 빈 공간이고 dist 에서 방문하지 않은(-1) 곳이라면 현재 거리에 +1을 한 다음 큐에 넣음
            {
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }
            if (broken == 0 && field[ny][nx] == '1' && dist[ny][nx][1] == 0)  // 
            {
                dist[ny][nx][1] = dist[y][x][broken] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    cout << -1;  // 도착 조건문에 걸리지 않았다면 도착 지점에 도달하지 못했다는 뜻이므로 -1 출력

    return (0);
}