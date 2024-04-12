#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string bracket = "";
    stack<char> s;
    unsigned int i = 0;
    unsigned int res = 0;

    cin >> bracket;
    while (i < bracket.length())
    {
        if (bracket[i] == '(')
            s.push(bracket[i]);
        else if (bracket[i] == ')')
        {
            if (bracket[i - 1] == '(')
            {
                s.pop();
                res = res + s.size();
            }
            else
            {
                s.pop();
                res++;
            }
        }
        i++;
    }
    cout << res << '\n';
    return (0);
}