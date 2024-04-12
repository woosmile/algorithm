#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> s_origin;
    stack<int> s_result;
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        s_origin.push(height);
    }
    while (s_origin.empty() == 0)
    {
        int right = s_origin.top();
        s_origin.pop();
        stack<int> s_copy = s_origin;
        while (s_copy.empty() == 0)
        {
            if (s_copy.top() > right)
                break ;
            s_copy.pop();
        }
        s_result.push(s_copy.size());
    }
    while (s_result.empty() == 0)
    {
        cout << s_result.top() << " ";
        s_result.pop();
    }
    return (0);
}