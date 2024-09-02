#include <iostream>

using namespace std;

int arr[10], isused[10];
int n, m;

void func(int depth)
{
    if (depth == m)  // 배열에 숫자가 다 찼으면 출력
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++)  // 1부터 n까지의 숫자 범위
    {
        if (!isused[i])  // 이전에 사용된 숫자인지 확인
        {
            isused[i] = true;  // 숫자를 사용했다고 기록
            arr[depth] = i;  // depth는 숫자가 들어갈 자리를 의미함
            func(depth + 1);  // 다음 자리에 들어갈 알맞은 숫자를 확인
            isused[i] = false;  // 재귀를 탈출했다면 이전에 사용한 숫자를 포함하기 위해 false로 바꾸고 다른 경우의 수 탐색
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    func(0);

    return (0);
}