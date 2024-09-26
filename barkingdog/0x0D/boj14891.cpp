#include <iostream>
#include <algorithm>

using namespace std;

string board[4];
int k;
int ans;

void solve(int gear, int dir) {
    int dirs[4] = {};
    dirs[gear] = dir;
    
    int gear_temp = gear;
    while (gear_temp > 0 && board[gear_temp][6] != board[gear_temp - 1][2]) {
        dirs[gear_temp - 1] = -dirs[gear_temp];
        gear_temp--;
    }

    gear_temp = gear;
    while (gear_temp < 3 && board[gear_temp][2] != board[gear_temp + 1][6]) {
        dirs[gear_temp + 1] = -dirs[gear_temp];
        gear_temp++;
    }
    
    for (int i = 0; i < 4; i++) {
        if (dirs[i] == 1)
            rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
        else if (dirs[i] == -1)
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        cin >> board[i];
    }

    cin >> k;

    while (k--) {
        int gear, dir;
        cin >> gear >> dir;
        solve(gear - 1, dir);
    }

    for (int i = 0; i < 4; i++) {
        if (board[i][0] == '1')
            ans = ans + (1 << i);
    }
    
    cout << ans;
    
    return 0;
}