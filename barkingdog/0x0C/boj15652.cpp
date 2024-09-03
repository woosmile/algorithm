#include <iostream>

using namespace std;

int n, m;
int arr[10];

bool check()
{
    int min = arr[0];

    for (int i = 0; i < m; i++)
    {
        if (min > arr[i])
            return false;
        min = arr[i];
    }
    return true;
}

void func(int k)
{
    if (k == m)
    {
        if (check())
        {
            for (int i = 0; i < m; i++)
                cout << arr[i] << ' ';
            cout << '\n';
        }
        return ;
    }
    
    for (int i = 1; i <= n; i++)
    {
        arr[k] = i;
        func(k + 1);
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