#include <iostream>
#include <vector>
#include <utility>

#define X second
#define Y first

using namespace std;

int dx[4] = {1, 0, -1, 0};  // 우, 상, 좌, 하
int dy[4] = {0, -1, 0, 1};

int board[105][105];
int n;
int x, y, d, g;
int ans;

vector< pair<int, int> > coords;  // 1이 표시된 모든 점의 위치를 보관하는 벡터

void square_counter(void)
{
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])  // 사각형 찾는 조건 (상, 하, 대각선 위치에 점이 있으면 사각형 1개 카운트)
                ans++;
        }
    }
}

void func(int k)
{
    if (k == g)
    {
        return ;
    }
    
    vector< pair<int, int> > temp = coords;  // 드래곤 커브를 구현을 위한 임시 벡터
    
    while (temp.size() > 1) {
        pair<int, int> end = temp.back();  // 끝점
        temp.pop_back();  // 끝점 삭제
        pair<int, int> cur = temp.back();  // 시작점
        
        int dir;
        for (dir = 0; dir < 4; dir++) {
            if (end.X + dx[dir] == cur.X && end.Y + dy[dir] == cur.Y)  // 끝점 기준으로 시작점이 상, 하, 좌, 우 어떤 방향으로 있는지 확인
                break ;
        }
        dir = (dir + 3) % 4;  // 위에서 찾은 방향 기준으로 시계방향 90도 회전
        pair<int, int> new_pos = coords.back();  // 가장 최신의 끝점을 기준으로 다음 위치에 점을 찍은 후 그 위치를 벡터에 넣음
        new_pos.Y = new_pos.Y + dy[dir];
        new_pos.X = new_pos.X + dx[dir];
        board[new_pos.Y][new_pos.X] = 1;
        coords.push_back(new_pos);
    }
    func(k + 1);  // g의 수만큼 재귀
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        board[y + dy[d]][x + dx[d]] = 1;
        coords.push_back({y, x});  // 초기 시작점
        coords.push_back({y + dy[d], x + dx[d]});  // 초기 끝점
        func(0);
        coords.clear();  // 다음 드래곤 커브를 위해 coords 벡터 초기화
    }
    
    square_counter();
    cout << ans;
    
    return 0;
}