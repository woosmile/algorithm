#include <iostream>
#include <vector>
#include <utility>

#define X second
#define Y first

using namespace std;

int n, m;  // n: x축, m: y축
int board_origin[10][10];  // 입력값을 받을 배열
int board_logic[10][10];  // 원본 배열 대신 카메라가 보는 영역을 저장할 배열
int ans = 2147483647;  // int 최대값으로 시작해서 처음 최소값도 잘 받을 수 있도록 함

int dx[4] = {0, 0, -1, 1};  // 상, 하, 좌, 우
int dy[4] = {-1, 1, 0, 0};

vector< pair<int, int> > cam_pos;  // 카메라의 좌표를 저장할 벡터

void fill_sharp(int x, int y, int dir)
{
    int nx = x;
    int ny = y;
    
    while(1) {
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)  // Out of Bound 확인
            return ;
        if (board_origin[ny][nx] == 6)  // 벽인지 확인
            return ;
        if (board_origin[ny][nx] == 0)  // 빈 공간이면 값을 증가해서 카메라가 보는 영역임을 표시함
            board_logic[ny][nx]++;  // 값을 대입하지 않고 증감연산을 하는 이유: 특정 영역을 여러대의 카메라가 볼 수 있기 때문
        
        nx = nx + dx[dir];  // 다음 좌표
        ny = ny + dy[dir];
    }
}

void remove_sharp(int x, int y, int dir)
{
    int nx = x;
    int ny = y;
    
    while(1) {
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            return ;
        if (board_origin[ny][nx] == 6)
            return ;
        if (board_origin[ny][nx] == 0)  // 빈 공간이면 증가시켰던 값을 다시 원상복구
            board_logic[ny][nx]--;
        
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }
}

int check_empty(int ans)
{
    int cnt = 0;
   
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board_origin[y][x] == 0 && board_logic[y][x] == 0)  // 원본배열에서도 빈 공간이고 로직이 돌아간 배열도 빈공간이면 카메라가 보지 못하는 사각지대임
                cnt++;
        }
    }
    cnt = min(ans, cnt);
    
    return cnt;
}

void cam_inspection(int k)  // k: 카메라 인덱스
{
    if (k == cam_pos.size())  // 마지막 카메라에 도달했으면 재귀 탈출하고 빈 공간을 체크함
    {
        ans = check_empty(ans);
        return;
    }
   
    pair<int, int> pos = cam_pos[k];  // 현재 카메라의 좌표를 가져옴

    // 카메라가 보는 영역을 체크하고 재귀로 들어간 다음 재귀를 빠져나오면 체크한 영역을 다시 원상 복구
    // 1번 카메라: 1방향씩 4번 확인
    // 2번 카메라: 2방향씩 2번 확인
    // 3번 카메라: 2방향씩 4번 확인
    // 4번 카메라: 3방향씩 4번 확인
    // 5번 카메라: 4방향씩 1번 확인
    if (board_origin[pos.Y][pos.X] == 1) {  
        fill_sharp(pos.X, pos.Y, 0);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);

        fill_sharp(pos.X, pos.Y, 1);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 1);

        fill_sharp(pos.X, pos.Y, 2);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 2);

        fill_sharp(pos.X, pos.Y, 3);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 3);
    }
    else if (board_origin[pos.Y][pos.X] == 2) {
        fill_sharp(pos.X, pos.Y, 2);
        fill_sharp(pos.X, pos.Y, 3);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 2);
        remove_sharp(pos.X, pos.Y, 3);

        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 1);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 1);
    }
    else if (board_origin[pos.Y][pos.X] == 3) {
        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 3);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 3);

        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 2);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 2);

        fill_sharp(pos.X, pos.Y, 1);
        fill_sharp(pos.X, pos.Y, 2);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 1);
        remove_sharp(pos.X, pos.Y, 2);

        fill_sharp(pos.X, pos.Y, 1);
        fill_sharp(pos.X, pos.Y, 3);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 1);
        remove_sharp(pos.X, pos.Y, 3);
    }
    else if (board_origin[pos.Y][pos.X] == 4) {
        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 1);
        fill_sharp(pos.X, pos.Y, 2);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 1);
        remove_sharp(pos.X, pos.Y, 2);

        fill_sharp(pos.X, pos.Y, 1);
        fill_sharp(pos.X, pos.Y, 2);
        fill_sharp(pos.X, pos.Y, 3);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 1);
        remove_sharp(pos.X, pos.Y, 2);
        remove_sharp(pos.X, pos.Y, 3);

        fill_sharp(pos.X, pos.Y, 2);
        fill_sharp(pos.X, pos.Y, 3);
        fill_sharp(pos.X, pos.Y, 0);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 2);
        remove_sharp(pos.X, pos.Y, 3);
        remove_sharp(pos.X, pos.Y, 0);

        fill_sharp(pos.X, pos.Y, 3);
        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 1);
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 3);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 1);
       
    }
    else if (board_origin[pos.Y][pos.X] == 5) {
        fill_sharp(pos.X, pos.Y, 0);
        fill_sharp(pos.X, pos.Y, 1);
        fill_sharp(pos.X, pos.Y, 2);
        fill_sharp(pos.X, pos.Y, 3);  
        cam_inspection(k + 1);
        remove_sharp(pos.X, pos.Y, 0);
        remove_sharp(pos.X, pos.Y, 1);
        remove_sharp(pos.X, pos.Y, 2);
        remove_sharp(pos.X, pos.Y, 3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board_origin[y][x];
            if (board_origin[y][x] >= 1 && board_origin[y][x] <= 5)  // 카메라 좌표 저장
                cam_pos.push_back({y, x});
        }
    }

    cam_inspection(0);
    cout << ans;
   
    return 0;
}
