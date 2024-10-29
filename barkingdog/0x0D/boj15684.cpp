#include <iostream>
#include <vector>
#include <utility>

#define X second
#define Y first

using namespace std;

int ladder[35][15];
vector< pair<int, int> > coords;

int n, m, h;
int ans = 2147483647;

bool check(void)
{
    for (int x = 1; x <= n; x++) {
        int cur = x;
        for (int y = 1; y <= h; y++) {
            if (ladder[y][cur])
                cur++;
            else if (ladder[y][cur - 1])
                cur--;
        }
        if (cur != x)
            return false;
    }
    return true;
}

// 백트래킹 풀이
void func(int k, int idx)
{
    if (k == 4)
        return ;
    
    for (int i = idx; i < coords.size(); i++) {
        ladder[coords[i].Y][coords[i].X] = 1;
        if (check())
            ans = min(ans, k);
        func(k + 1, i + 1);
        ladder[coords[i].Y][coords[i].X] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        ladder[y][x] = 1;
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x < n; x++) {
            if (ladder[y][x] || ladder[y][x - 1] || ladder[y][x + 1])
                continue ;
            coords.push_back({y, x});
        }
    }

    if (check())
    {
        cout << 0;
        return 0;
    }

    int size = coords.size();
    
    // for (int i = 0; i < size; i++) {
    //     ladder[coords[i].Y][coords[i].X] = 1;
    //     if (check())
    //         ans = min(ans, 1);
    //     for (int j = i + 1; j < size; j++) {
    //         ladder[coords[j].Y][coords[j].X] = 1;
    //         if (check())
    //             ans = min(ans, 2);
    //         for (int k = j + 1; k < size; k++) {
    //             ladder[coords[k].Y][coords[k].X] = 1;
    //             if (check())
    //                 ans = min(ans, 3);
    //             ladder[coords[k].Y][coords[k].X] = 0;
    //         }
    //         ladder[coords[j].Y][coords[j].X] = 0;
    //     }
    //     ladder[coords[i].Y][coords[i].X] = 0;
    // }

    func(1, 0);
    
    if (ans == 2147483647)
        ans = -1;
    
    cout << ans;
    
    return 0;
}
