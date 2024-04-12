#include <iostream>
#include <stack>

using namespace std;

const int MX = 100005;
int dat[MX];
int pos;

int top()
{
    if (pos > 0)
        return dat[pos - 1];
    return (dat[0]);
}

void pop()
{
    if (pos > 0)
        pos--;
}

void push(int a)
{
    dat[pos++] = a; 
}

bool empty()
{
    if (pos == 0)
        return (true);
    return (false);
}

int size()
{
    return (pos);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            push(num);
        }
        else if (cmd == "pop")
        {
            if (empty() != true)
            {
                cout << top() << '\n';
                pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << (int)empty() << '\n';
        }
        else if (cmd == "top")
        {
            if (empty() != true)
                cout << top() << '\n';
            else
                cout << -1 << '\n';
        }

        cmd_cnt--;
    }

    return (0);
}