#include <iostream>
#include <vector>
#include <algorithm>

#define X second
#define Y first

using namespace std;

vector<vector< pair<int, int> >> block;

int n, m;
int board[510][510];
int ans;

bool isAdj(pair<int, int>& a, pair<int, int>& b) {
    if (a.X == b.X)
        return (abs(a.Y - b.Y) == 1);
    if (a.Y == b.Y)
        return (abs(a.X - b.X) == 1);
    return false;
}

bool isConn(vector< pair<int, int> >& shape) {
    bool flag = false;

    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (isAdj(shape[i], shape[j]))
                cnt++;
        }
        if (cnt == 0)
            return false;
        if (cnt >= 2)
            flag = true;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }

    vector<int> brute(16);
    fill(brute.begin() + 12, brute.end(), 1);
    
    do {
        vector< pair<int, int> > shape;
        for(int i = 0; i < 16; i++) {
            if (brute[i] == 1) {
                shape.push_back({i / 4, i % 4});
            }
        }
        if (isConn(shape))
            block.push_back(shape);
    } while(next_permutation(brute.begin(), brute.end()));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (auto shape : block) {
                int total = 0;
                for (auto coor : shape) {
                    total = total + board[y + coor.Y][x + coor.X];
                }
                ans = max(ans, total);
            }
        }
    }

    cout << ans;
    
    return 0;
}