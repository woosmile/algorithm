#include <iostream>

using namespace std;

int n, m;
int arr[10];
int e[10];
int inused[10001];

void sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (e[i] > e[j])
            {
                int temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (!inused[e[i]])
        {
            inused[e[i]] = true;
            arr[k] = e[i];
            func(k + 1);
            inused[e[i]] = false;
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
    sort();
    func(0);
    return (0);
}