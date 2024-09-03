#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int e[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp != e[i])  // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        {
            arr[k] = e[i];
            tmp = arr[k];
            func(k + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> e[i];
    sort(e, e + n);
    func(0);
    return (0);
}  