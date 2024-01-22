#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int>idx;
    int n, k, cnt;

    cin >> n;
    cin >> k;

    for (int i = 1; i <= n; i++)
    {
        idx.push_back(i);
    }

    auto idx_it = idx.begin();

    cout << "<";
    while (idx.size() != 1)
    {
        cnt = 0;
        while (cnt < k - 1)
        {
            idx_it++;
            cnt++;
            if (idx_it == idx.end())
                idx_it = idx.begin();
        }
        cout << *idx_it << ", ";
        idx_it = idx.erase(idx_it);
        if (idx_it == idx.end())
            idx_it = idx.begin();

    }
    cout << *idx.begin() << ">";

    return (0);
}