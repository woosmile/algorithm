#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string s = "";
        bool iswrong = false;
        stack<char> br;
        getline(cin, s);
        if (s[0] == '.')
            break ;
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == '(')
                br.push(s[i]);
            else if (s[i] == ']')
            {
                if (br.size() == 0)
                {
                    iswrong = true;
                    break ;
                }
                if (br.top() == '[')
                    br.pop();
                else
                {
                    iswrong = true;
                    break ;
                }
            }
            else if (s[i] == ')')
            {
                if (br.size() == 0)
                {
                    iswrong = true;
                    break ;
                }
                if (br.top() == '(')
                    br.pop();
                else
                {
                    iswrong = true;
                    break ;
                }
            }
        }
        if (br.size() != 0)
            iswrong = true;
        if (iswrong == true)
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
    }
    return (0);
}