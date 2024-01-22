#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    list<char> ans;

    cin >> cnt;
    while (cnt > 0)
    {
        string password;
        cin >> password;
        ans.clear();
        auto ans_it = ans.begin();
        for (auto c : password)
        {
            if (c == '<')
            {
                if (ans_it != ans.begin())
                    ans_it--;
            }
            else if (c == '>')
            {
                if (ans_it != ans.end())
                    ans_it++;
            }
            else if (c == '-')
            {
                if (ans_it != ans.begin())
                {
                    ans_it--;
                    ans_it = ans.erase(ans_it);
                }
            }
            else
            {
                if (ans_it != ans.end())
                {
                    ans.insert(ans_it, c);
                }
                else
                {
                    ans.insert(ans_it, c);
                    ans_it = ans.end();
                }
            }
        }
        ans.push_back('\n');
        cnt--;
        for (auto c : ans)
            cout << c;
    }
    return (0);
}