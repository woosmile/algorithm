#include <iostream>
#include <queue>
#include <utility>

#define Y first
#define X second

using namespace std;

int field[60][60];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m, r, c, dir;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> dir;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> field[y][x];
        }
    }

    int move = 0;
    while (1) {
        if (field[r][c] == 0)
        {
            move++;
            field[r][c] = -1;
        }
        bool clean = false;
        
        for (int i = 0; i < 4; i++) {
            dir = (dir + 3) % 4;

            int nx = c + dx[dir];
            int ny = r + dy[dir];

            if (field[ny][nx] == 0)
            {
                c = nx;
                r = ny;
                clean = true;
                break ;
            }
        }

        if (clean)
            continue ;
        if (field[r - dy[dir]][c - dx[dir]] == 1)
            break ;
        r = r - dy[dir];
        c = c - dx[dir];
    }
    
    cout << move;
    
    return 0;
}