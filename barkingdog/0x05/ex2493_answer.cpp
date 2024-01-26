#include <iostream>
#include <stack>
#include <utility>

#define X first
#define Y second

using namespace std;

stack< pair<int,int> > tower;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    tower.push({100000001, 0});
    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;
        while (tower.top().X < height)
            tower.pop();
        cout << tower.top().Y << " ";
        tower.push({height, i});
    }
    return (0);
}

