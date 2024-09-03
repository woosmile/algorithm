#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
int e[10];
int inused[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << e[arr[i]] << ' ';
        cout << '\n';
        return ;
    }
    int st = arr[k];
    if (k != 0)
        st = arr[k - 1] + 1;
    for (int i = st; i < n; i++)
    {
        if (!inused[i])
        {
            inused[i] = true;
            arr[k] = i;
            func(k + 1);
            inused[i] = false;
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