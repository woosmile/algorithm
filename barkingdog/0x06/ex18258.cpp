#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n;

    cin >> n;

    while (n-- > 0)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << -1 << "\n";

        }
        else if (s == "size")
        {
            cout << q.size() << "\n";
        }
        else if (s == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if (s == "front")
        {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << -1 << "\n";           
        }
        else if (s == "back")
        {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << -1 << "\n";   
        }
    }
    return (0);
}