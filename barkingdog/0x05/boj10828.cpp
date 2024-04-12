#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> basket;
    int cmd_cnt;

    cin >> cmd_cnt;

    while (cmd_cnt > 0)
    {
        string cmd;
        int num;
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> num;
            basket.push(num);
        }
        else if (cmd == "pop")
        {
            if (basket.empty() != 1)
            {
                cout << basket.top() << '\n';
                basket.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << basket.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << basket.empty() << '\n';
        }
        else if (cmd == "top")
        {
            if (basket.empty() != 1)
                cout << basket.top() << '\n';
            else
                cout << -1 << '\n';
        }

        cmd_cnt--;
    }

    return (0);
}