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

void move(int dir)  // 0 상, 1 하, 2 좌, 3 우
{
    if (dir == 0)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                
            }
        }
    }
    else if (dir == 1)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                
            }
        }
    }
    else if (dir == 2)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                
            }
        }
    }
    else if (dir == 3)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                
            }
        }
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
            move(dir);
        }
        check_val();
    }

    cout << ans;

    return (0);
}