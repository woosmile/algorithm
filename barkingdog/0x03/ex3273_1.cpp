#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num[1000001] = {}, size, find, ans = 0;
    bool occur[2000001];

    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> num[i];
    cin >> find;

    for (int i = 0; i < size; i++)
    {
        if (find - num[i] > 0 && occur[find - num[i]] == true)
            ans++;
        occur[num[i]] = true;
    }
    cout << ans;
    return (0);
}