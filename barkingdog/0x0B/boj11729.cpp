#include <iostream>

using namespace std;

void recursive(int a, int b, int n)
{
    if (n == 1)  // 위에 원판이 없으므로 기둥 a에서 b로 바로 이동
    {
        cout << a << ' ' << b << '\n';  
        return ;
    }
    recursive(a, 6 - a - b, n - 1);  // n보다 작은 원판(n - 1)을 기둥 a에서 기둥 6-a-b로 이동
    cout << a << ' ' << b << '\n';  // n원판을 기둥 a에서 기둥 b로 이동
    recursive(6 - a - b, b, n - 1);  // n보다 작은 원판(n - 1)을 기둥 6-a-b에서 기둥 b로 이동
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    
    cin >> k;
    
    cout << (1 << k) - 1 << '\n';  // k개의 원판이 있는 하노이탑 문제의 이동 횟수 수열의 일반항(2의 k승 - 1)
    recursive(1, 3, k);  // 1번째 칸에서 3번째 칸으로 k개의 원판을 이동
    
    return (0);
}