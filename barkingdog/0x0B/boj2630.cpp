#include <iostream>

using namespace std;

int paper[130][130];
int n;

int answer[2];

bool check(int n, int x, int y)
{
    for (int i = y; i < y + n; i++)  // y, x부터 n만큼의 범위를 확인
    {
        for (int j = x; j < x + n; j++)
        {
            if (paper[y][x] != paper[i][j])  // 같은 값인지 확인
                return (false);
        }
    }
    answer[paper[y][x]]++;  // 같은 색으로만 구성되어있다면 그 색의 개수 증가
    return (true);
}

void divide(int n, int x, int y)
{
    if (check(n, x, y) == true)
        return ;

    n = n / 2;  // 한 변의 길이를 2로 나눠서 4개의 사각형으로 나눔

    for (int i = 0; i < 4; i++)  // 4개의 사각형 구역으로 나누어서 재귀적으로 호출
    {
        if (i == 0)
            divide(n, x, y);
        else if (i == 1)
            divide(n, x + n, y);
        else if (i == 2)
            divide(n, x, y + n);
        else
            divide(n, x + n, y + n);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    
    divide(n, 0, 0);
    
    for (int i = 0; i < 2; i++)
        cout << answer[i] << '\n';
    
    return 0;
}