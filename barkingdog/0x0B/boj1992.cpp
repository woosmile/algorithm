#include <iostream>

using namespace std;

int n;
char field[70][70];

bool check(int n, int x, int y)
{
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (field[y][x] != field[i][j])
                return false;
        }
    }
    return true;
}

void func(int n, int x, int y)
{
    if (check(n, x, y) == true)
    {
        cout << field[y][x];
        return ;
    }
    cout << '(';  // 여는 괄호가 있다는 것은 같은 색이 아니므로 함수를 한 번 더 호출했음을 의미함(재귀적 호출)

    n = n / 2;
    
    for (int i = 0; i < 2; i++)  // 4구역으로 나누어서 재귀적으로 호출(x, y는 각 구역의 시작점)
        for (int j = 0; j < 2; j++)
            func(n, x + (j * n), y + (i * n));

    cout << ')';  // 4구역의 재귀적 호출이 끝나면 닫는 괄호를 출력
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int y = 0; y < n; y++)
        cin >> field[y];

    func(n, 0, 0);
    
    return 0;
}