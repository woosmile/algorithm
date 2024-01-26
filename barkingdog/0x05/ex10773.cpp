// #include <bits/stdc++.h>

#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, total = 0;
    stack<int> s;

    cin >> k;
    while (k > 0)
    {
        k--;
        int num;
        cin >> num;

        if (num == 0)
        {
            if (s.empty() == 0)
                s.pop();
        }
        else
        {
            s.push(num);
        }
    }
    while (s.empty() == 0)
    {
        total = total + s.top();
        s.pop();
    }
    cout << total;
    return (0);
}