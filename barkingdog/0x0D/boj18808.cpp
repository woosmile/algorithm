#include <iostream>

using namespace std;

int n, m, k;  // n: 보드 행, m: 보드 열, k: 스티커 개수
int board[50][50];  // 스티커가 붙여질 보드

int r, c;  // r: 스티커 행, c: 스티커 열
int sticker[20][20];  // 원본 스티커 배열

// 스티커 회전 함수
void rotate_sticker()
{
    int sticker_rotate[20][20];  // 스티커 회전 시 값을 저장할 임시 배열

    for (int y = 0, x_rot = 19; y < 20; y++, x_rot--) {
        for (int x = 0; x < 20; x++) {
            sticker_rotate[x][x_rot] = sticker[y][x];
        }
    }

    int temp = r;
    r = c;
    c = temp;

    for (int y = 0; y < 20; y++) {
        fill(sticker[y], sticker[y] + 20, 0);
    }
    
    for (int y = 0; y < 20; y++) {
        for (int x = 20 - c, x_origin = 0; x < 20; x++, x_origin++) {
            sticker[y][x_origin] = sticker_rotate[y][x];
        }
    }
}

void paste_sticker(int y, int x) {
    for (int y_s = 0; y_s < r; y_s++) {
        for (int x_s = 0; x_s < c; x_s++) {
            if (sticker[y_s][x_s] == 1)
                board[y + y_s][x + x_s] = sticker[y_s][x_s];
        }
    }
}

bool check_paste_sticker()
{
    int y = 0, x = 0, y_s = 0, x_s = 0;
    
    for (y = 0; y < n; y++) {
        for (x = 0; x < m; x++) {
            for (y_s = 0; y_s < r; y_s++) {
                bool flag = true;
                for (x_s = 0; x_s < c; x_s++) {
                    if (sticker[y_s][x_s] == 1) {
                        int y_origin = y + y_s;
                        int x_origin = x + x_s;

                        if (y_origin >= n || x_origin >= m)
                        {
                            flag = false;
                            break ;
                        }
                        else
                        {
                            if (board[y_origin][x_origin] == 1)
                            {
                                flag = false;
                                break ;
                            }
                        }
                    }
                }
                if (flag == false)
                    break ;
            }
            if (y_s == r && x_s == c)
            {
                paste_sticker(y, x);
                return true;
            }
        }
    }
    return false;
}

int count_zero()
{
    int cnt = 0;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board[y][x] == 1)
                cnt++;
        }
    }
    return (cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                cin >> sticker[y][x];
            }
        }
        int rot_cycle = 0;
        while (rot_cycle < 4) {
            if (check_paste_sticker())
                break ;
            else
            {
                rotate_sticker();
                rot_cycle++;
            }
        }
        for (int y = 0; y < 20; y++) {
            fill(sticker[y], sticker[y] + 20, 0);
        }
    }
    
    cout << count_zero();
    
    return 0;
}