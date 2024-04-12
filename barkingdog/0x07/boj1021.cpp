#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n, f, cycle = 0;

    cin >> n >> f;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (f-- > 0)
    {
        int val;
        cin >> val;

        int idx = find(dq.begin(), dq.end(), val) - dq.begin();
        while (dq.front() != val)
        {
            // if (idx < dq.size() - idx)
            if (dq.size() / 2 >= idx)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cycle++;
        }
        dq.pop_front();
    }
    cout << cycle << "\n";
    return (0);
}