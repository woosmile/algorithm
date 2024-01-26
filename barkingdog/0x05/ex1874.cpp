// #include <bits/stdc++.h>

#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0, inc = 1, flag = 0;
    stack<int> s;
    list<bool> op;
    
    cin >> n;

    while (cnt < n)
    {
        cnt++;
        int num;
        cin >> num;
        while (inc <= num)
        {
            s.push(inc);
            op.push_back(true);
            inc++;
        }
        if (s.top() != num)
        {
            flag = 1;
        }
        s.pop();
        op.push_back(false);
    }
    if (flag == 1)
        cout << "NO" << "\n";
    else
    {
        for(auto c : op)
        {
            if (c == true)
                cout << "+" << "\n";
            else
                cout << "-" << "\n";
        }
    }
    return (0);
}

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  while (n--) {
    int t;
    cin >> t;
    while (cnt <= t) {
      S.push(cnt++);
      ans += "+\n";
    }
    if (S.top() != t) {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}