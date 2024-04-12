#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<char> s;
    string str;
    int sum = 0;
    int sum_temp = 1;

    cin >> str;

    unsigned int i = 0;
    while (i < str.length())
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
            sum_temp = sum_temp * 2;
        }
        else if (str[i] == '[')
        {
            s.push(str[i]);
            sum_temp = sum_temp * 3;
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return (0);
            }
            if (str[i - 1] == '(')
                sum = sum + sum_temp;
            s.pop();
            sum_temp = sum_temp / 2;
        }
        else
        {
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return (0);
            }
            if (str[i - 1] == '[')
                sum = sum + sum_temp;
            s.pop();
            sum_temp = sum_temp / 3;
        }
        i++;
    }
    if (s.empty())
        cout << sum;
    else
        cout << 0;
    return (0);
}