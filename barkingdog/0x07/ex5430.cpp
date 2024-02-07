#include <deque>
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, len;
    string cmd, n;
    deque<int> d;

    cin >> tc;

    while (tc-- > 0)
    {
        cin >> cmd;
        cin >> len;
        cin >> n;

        string::iterator str_iter = n.begin();

        size_t num_start, num_end;
        string n_sub;
        while (str_iter != n.end())
        {
            if (*str_iter >= '0' && *str_iter <= '9')
            {
                num_start = str_iter - n.begin();
                while (*str_iter >= '0' && *str_iter <= '9' && str_iter != n.end())
                    str_iter++;
                num_end = str_iter - n.begin() - 1;
                n_sub = n.substr(num_start, num_end);
                d.push_back(strtol(n_sub.c_str(), NULL, 10));
            }
            if (str_iter != n.end())
                str_iter++;
        }
        str_iter = cmd.begin();
        while (str_iter != cmd.end())
        {
            if (*str_iter == 'R')
            {
                if (len <= 0)
                {
                    cout << "error\n";
                    break ;
                }
                else
                {
                    deque<int> rev_d;

                    while (d.size() > 0)
                    {
                        rev_d.push_back(d.back());
                        d.pop_back();
                    }
                    d = rev_d;
                }
            }
            else if (*str_iter == 'D')
            {
                if (len <= 0)
                {
                    cout << "error\n";
                    break ;
                }
                else
                {
                    len--;
                    d.pop_front();
                }
            }
            str_iter++;
        }
        while (d.size() > 0)
        {
            if (d.size() == len)
                cout << "[";
            cout << d.front();
            d.pop_front();
            if (d.size() > 0)
                cout << ",";
            else
                cout << "]\n";
        }
    }

    return (0);
}