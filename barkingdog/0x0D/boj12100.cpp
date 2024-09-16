// 1. 5자리 수열인데 각 자리마다 0~3(4방향)의 범위를 가지는 모든 경우의 개수 구하기 (가장 바깥 반복문)
// 2. 로직이 적용될 배열에 원본 배열을 복사하기
// 3. 수열 자리수에 따라서 4방향 별로 알맞은 로직 5회 진행하기
// 4. 5번의 횟수가 끝나면 로직이 적용된 배열을 순회하면서 가장 큰 값을 찾고 최대값 갱신하기
// 5. 2~4 과정 반복
// 시간 복잡도 계산 = {(20 * 20) + (5 * 20 * 20) + (20 * 20)} * 1024 = 2867200, (2번 + 3번 + 4번) * 1번

#include <iostream>

using namespace std;

int n;
int board[30][30];
int logic[30][30];

int ans;

void rotate()
{
    int temp[30][30];

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            temp[y][x] = board[y][x];

    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            logic[y][x] = temp[n - 1 - x][y];
}

void tilt(int dir)
{
    while(dir--)
        rotate();
    
    for (int y = 0; y < n; y++)
    {
        int tilted[30] = {};
        int idx = 0;
        for (int x = 0; x < n; x++)
        {
            if (logic[y][x] == 0)
                continue ;

            if (tilted[idx] == 0)
                tilted[idx] = logic[y][x];
            else if (tilted[idx] == logic[y][x])
                tilted[idx++] = tilted[idx] * 2;
            else
                tilted[++idx] = logic[y][x];
        }
        for (int x = 0; x < n; x++)
            logic[y][x] = tilted[x];
    }
}

void check_val()
{
    int val = logic[0][0];

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (val < logic[y][x])
                val = logic[y][x];
        }
    }
    ans = max(ans, val);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            cin >> board[y][x];
    }
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            logic[y][x] = board[y][x];
    }

    for (int total = 0; total < (1 << (2 * 5)); total++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
                logic[y][x] = board[y][x];
        }

        int brute = total;
        for (int i = 0; i < 5; i++)
        {
            int dir = brute % 4;
            brute = brute / 4;
            tilt(dir);
        }
        check_val();
    }
    cout << ans;

    return (0);
}