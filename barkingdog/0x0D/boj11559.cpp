#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

#define X first
#define Y second

using namespace std;

string board[12];  // 입력값
bool vis[12][6];  // BFS 방문여부 확인
bool isPuyo;  // 4개의 영역이 모여서 Puyo 발생 여부 확인
int ans;  // 출력값

int dx[4] = {0, 0, -1, 1};  // BFS OOB 확인
int dy[4] = {-1, 1, 0, 0};

void resetVisit()  // Vis 배열 초기화
{
    for (int y = 0; y < 12; y++) {
        for (int x = 0; x < 6; x++) {
            vis[y][x] = false;
        }
    }
}

void puyo(int x, int y)  // puyo에 해당하는지 확인
{
    char color = board[y][x];  // 컬러값 
    
    queue< pair<int, int> > q;  // BFS를 체크할 큐
    vector< pair<int, int> > v;  // 영역이 상하좌우로 4개가 연결되어있는지 체크할 벡터

    q.push({x, y});
    v.push_back({x, y});

    vis[y][x] = true;  // 현재 좌표 방문표시

    while(!q.empty()) {  // BFS
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12)  // OOB
                continue ;
            if (vis[ny][nx] || board[ny][nx] != color)  // 이전에 방문했거나 컬러가 같지 않다면 패스
                continue ;
            q.push({nx, ny});
            v.push_back({nx, ny});
            vis[ny][nx] = true;  // 방문표시
        }
    }
    if (v.size() >= 4) {  // 4개 이상이 들어있다면 Puyo 발생
        isPuyo = true;
        for (int i = 0; i < v.size(); i++) {
            pair<int, int> cur = v[i];
            board[cur.Y][cur.X] = '.';  // Puyo가 발생한 좌표를 .으로 변경(빈공간)
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
        cin >> board[i];  // 입력값 대입

    do {
        isPuyo = false;  // 새로운 경우에서 Puyo를 다시 확인해야하므로 false로 초기화

        for (int x = 0; x < 6; x++) {  // 컬러가 있는 공간을 맨 아래로 내리는 로직(=빈공간인 .을 위로 올리는 로직)
            for (int y = 10; y >= 0; y--) {  // 아래쪽부터 시작 (정확히는 맨아래 한칸 위)
                int temp = y;
                while (temp < 11 && board[temp + 1][x] == '.') {  // 현재 좌표 기준 아래쪽이 .이라면 Swap
                    swap(board[temp + 1][x], board[temp][x]);
                    temp++;
                }
            }
        }
        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 6; x++) {
                if (board[y][x] != '.')  // 빈공간이 아니라면 BFS로 확인
                    puyo(x, y);
            }
        }
        if (isPuyo)  // Puyo가 발생했다면 ans 증가
            ans++;
        resetVisit();  // 다음 경우의 수를 확인하기 위해 vis 배열 초기화
    } while (isPuyo);  // 더 이상 Puyo가 발생하지 않을 때까지 반복

    cout << ans;
    
    return 0;
}