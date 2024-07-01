#include <iostream>  // cout, cin
#include <utility>  // pair
#include <queue>  // queue

#define X second  // pair 접근을 쉽게 하기 위함
#define Y first

using namespace std;

int field[52][52];  // BFS로 확인할 값이 들어있는 2차원 배열
int visit[52][52];  // BFS로 값 확인 시 방문 여부를 기록하는 2차원 배열
int dx[4] = {0, 0, -1, 1};  // 2차원 배열의 상, 하, 좌, 우 index를 쉽게 접근하기 위해 사용
int dy[4] = {-1, 1, 0, 0};

int tc;
int width, height, veget;

int main(void)
{
    // C 표준 스트림(stdin, stdout, stderr)과의 동기화 비활성화 (C++ 표준 스트림만 사용함으로써 입출력 성능 향상 단, C 표준 스트림과 혼합해서 사용 시 유의)
    ios::sync_with_stdio(0);
    // cin과 cout의 묶음 해제 (기본적으로 cin을 입력받기 전에 cout이 flush 되는데 이것을 안함으로써 입출력 성능 향상 단, 입력과 출력이 섞여서 보일 수 있음)
    cin.tie(0); 

    cin >> tc;

    for (int cycle = 0; cycle < tc; cycle++)
    {
        int bug = 0;

        cin >> width >> height >> veget;

        for (int veget_cnt = 0; veget_cnt < veget; veget_cnt++)
        {
            int pos_x = 0, pos_y = 0;

            cin >> pos_x >> pos_y;

            field[pos_y][pos_x] = 1;
        }

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                if (field[y][x] == 0 || visit[y][x] == 1)  // 확인할 값이 0이거나 방문한 기록이 있으면 패스
                    continue ;
                queue< pair<int, int> >q;  
                visit[y][x] = 1;  // 위 if 문에 안걸렸다면 방문해야 할 위치이므로 방문했다는 기록을 하고
                q.push({y, x});  // 그 위치를 큐에 넣음
                while (!q.empty())  // 큐에 남아있는 것이 없을 때까지
                {
                    pair<int, int> cur = q.front();  // 큐에 있는 값을 불러오고
                    q.pop();  // 위에서 값을 불러왔으니 불러온 요소를 pop을 해서 지운 다음
                    for (int i = 0; i < 4; i++)  // 불러온 값의 상 하 좌 우 값을 확인함
                    {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];

                        if (nx < 0 || ny < 0 || nx >= width || ny >= height)  // 범위를 벗어났는지 체크
                            continue ;
                        if (field[ny][nx] == 0 || visit[ny][nx] == 1)  // 상 하 좌 우의 값이 확인해야 할 값인지, 방문했었는지 체크
                            continue ;
                        visit[ny][nx] = 1;  // 위 if 문에 안걸렸다면 방문해야 할 위치이므로 방문했다는 기록을 하고
                        q.push({ny, nx});  // 그 위치를 큐에 넣음
                    }
                }
                bug++;  // BFS가 한번 끝날 때마다 벌레의 개수가 증가해야 함
            }
        }

        cout << bug << "\n";

        for (int y = 0; y < height; y++)  // 다음 테스트 케이스를 위한 변수 초기화
        {
            fill(field[y], field[y] + width, 0);
            fill(visit[y], visit[y] + width, 0);
        }
    }

    return (0);
}