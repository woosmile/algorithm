#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> card;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        card.push(i);
    }
    
    while (card.size() > 1)
    {
        card.pop();
        int num = card.front();
        card.pop();
        card.push(num);
    }

    cout << card.front() << "\n";

    return (0);
}