#include <iostream>

int num[100001];
bool rec[2000001];

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size, find, ans = 0;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    cin >> find;
    for (int i = 0; i < size; i++)
    {
        if (find - num[i] > 0)
        {
            if (rec[find - num[i]] == true)
            {
                ans++;
            }
            rec[num[i]] = true;
        }
    }
    cout << ans;
    return (0);
}