#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X second
#define Y first

using namespace std;

string field[5];
bool mask[25];
int cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        cin >> field[i];

    fill(mask + 7, mask + 25, true);  // 25명 중 7공주가 될 후보만을 뽑기 위해 7개만 false로 두고 나머지는 true인 수열로 시작 (항상 false가 7개로 고정인 수열이 생성될 예정)

    do
    {
        queue< pair<int, int> > q;  // 인접한 값을 BSF로 확인하기 위한 큐
        bool isp7[5][5] = {};  // 수열에 하당하는 자리 체크
        bool visit[5][5] = {};  // 방문 여부 체크

        for (int i = 0; i < 25; i++)
        {
            int x = i % 5;  // 이중 for를 쓰지 않고 x, y 인덱스 계산
            int y = i / 5;
            if (mask[i] == 0)
            {
                isp7[y][x] = true;  // 수열에 해당하는 자리이므로 true로 체크
                if (q.empty())  // 큐가 비어있다면 만들어진 해당 수열의 시작점부터 BSF를 진행하기 위해 큐에 넣고 방문여부 체크
                {
                    q.push({y, x});
                    visit[y][x] = true;
                }
            }
        }

        int s_cnt = 0;  // 7명 중에서 S의 명수
        int p_cnt = 0;  // S, Y를 모두 포함한 명수

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            p_cnt++;
            if (field[cur.Y][cur.X] == 'S')
                s_cnt++;
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visit[ny][nx] || !isp7[ny][nx])  // 다음 좌표의 방문여부, 수열에 포함되는지 여부 확인
                    continue ;
                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }
        cnt = cnt + (p_cnt >= 7 && s_cnt >= 4);  //  인접한 S, Y의 총 명수와 S의 명수가 조건을 만족하면 cnt 증가

    } while (next_permutation(mask, mask + 25));  // 항상 false가 7개로 고정인 25자리의 모든 수열 생성
    
    cout << cnt;

    return (0);
}