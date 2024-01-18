#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> res;
    int cycle;
    string init;
    char mode;

    cin >> init;
    for (auto c : init)
        res.push_back(c);
    cin >> cycle;

    list<char>::iterator res_it = res.end();
    while (cycle > 0)
    {
        cin >> mode;
        switch (mode)
        {
            case 'P':
            {
                char add_alpha;
                cin >> add_alpha;
                res.insert(res_it, add_alpha);
                break ;
            }
            case 'L':
            {
                if (res_it != res.begin())
                    res_it--;
                break ;
            }
            case 'D':
            {
                if (res_it != res.end())
                    res_it++;
                break ;
            }
            case 'B':
            {
                //지울 때 자리 갱신하기
                if (res_it != res.begin())
                {
                    res_it--;
                    res_it = res.erase(res_it);
                }
                break ;
            }
            default:
            {
                break ;
            }
        }
        cycle--;
    }
    for (auto c : res)
        cout << c;
}