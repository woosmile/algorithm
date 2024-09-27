#include <iostream>

using namespace std;

int map[21][21];  // 입력값
int n, m, x, y, k;  // 입력값

int dice[7];  // 주사위 배열(0은 안씀)
// 주사위를 굴릴 때 값을 이동시킬 때 사용할 인덱스 배열
int idx[5][4] = {
  {},
  {2, 3, 6, 1}, // 동: 1->2, 2->3, 3->6, 6->1
  {2, 1, 6, 3}, // 서: 3->2, 2->1, 1->6, 6->3
  {5, 2, 4, 6}, // 북: 6->5, 5->2, 2->4, 4->6
  {2, 5, 6, 4}, // 남: 4->2, 2->5, 5->6, 6->4
};
//  윗면이 2이고, 동쪽을 바라보는 방향이 3, 밑면은 6
//     [4]
//  [1][2][3]
//     [5]
//     [6]

// 주사위를 굴릴 때 범위를 벗어나는지 확인
bool check_oob(int nx, int ny) {
    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        return false;
    return true;
}

void roll(int dir){
    int tmp[7];

    for (int i = 1; i <= 6; i++)  // 주사위 값을 임시 변수에 복사
        tmp[i] = dice[i];

    for (int i = 0; i < 4; i++)  // 주사위를 굴릴 때 값 이동 (동,서,남,북 모든 경우에서 4번의 이동이 발생함)
        tmp[idx[dir][i]] = dice[idx[dir][(i + 3) % 4]];
    
    for (int i = 1; i <= 6; i++)  // 이동된 값을 원본 주사위 배열에 복사
        dice[i] = tmp[i];
}

void move_dice(int dir) {
    int nx = x;
    int ny = y;

    if (dir == 1)  // 동
        nx++;
    else if (dir == 2)  // 서
        nx--;
    else if (dir == 3)  // 북
        ny--;
    else if (dir == 4)  // 남
        ny++;

    if (check_oob(nx, ny)) {
        x = nx;
        y = ny;
        
        roll(dir);

        if (map[y][x] == 0)
            map[y][x] = dice[6];  // 맵의 값이 0이라면 주사위 값을 바닥면에 복사
        else {
            dice[6] = map[y][x];  // 맵의 값이 0이 아니라면 맵의 값을 주사위 바닥면에 복사하고
            map[y][x] = 0;  // 맵의 값을 0으로 초기화
        }
        cout << dice[2] << '\n';  // 주사위 윗면 출력
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (k--) {
        int dir;
        cin >> dir;
        move_dice(dir);
    }
    
    return (0);
}