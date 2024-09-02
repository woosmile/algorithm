#include <iostream>

using namespace std;

bool inused1[40];  // 열(y)
bool inused2[40];  // 좌측 하단과 우측 상단을 잇는 대각선(x + y)
bool inused3[40];  // 좌측 상단과 우측 하단을 잇는 대각선(x - y + n - 1)

int n;
int cnt;

void func(int depth)  // depth는 x를 의미함 (코드 흐름이 y축 기준으로 내려가는 느낌이 아니라 x축 기준으로 오른쪽으로 가는 흐름)
{
    if (depth == n)  // depth가 n과 같아졌다는 것은 모든 퀸을 다 놓았음을 의미함
    {
        cnt++;
        return ;
    }
    for (int i = 0; i < n; i++)  // i는 y를 의미함
    {
        if (inused1[i] || inused2[depth + i] || inused3[depth - i + n - 1])  // 퀸이 놓이는 자리 체크
            continue ;
        inused1[i] = true;
        inused2[depth + i] = true;
        inused3[depth - i + n - 1] = true;  // n - 1을 더하는 이유는 x - y가 음수가 되는 것을 막기 위함
        func(depth + 1);
        inused1[i] = false;  // 이전 상태로 돌아왔으니 이전 상태를 포함한 다른 경우의 수를 확인하기 위해 false로 바꿈
        inused2[depth + i] = false;
        inused3[depth - i + n - 1] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;

    return (0);
}