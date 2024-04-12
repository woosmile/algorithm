#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num[10] = {}, ans = 1, input;

    cin >> input;

    while (input > 0)
    {
        num[input % 10]++;
        input = input / 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue ;
        ans = max(ans, num[i]);
    }
    ans = max(ans, (num[6] + num[9] + 1) / 2);
    cout << ans;
    
    return (0);
}