// algorithm : dfs
// http://boj.kr/474494b53afc4871a77f14bb632633da

#include <iostream>

using namespace std;

bool map[50][50];
bool visit[50][50];

int x, y;

int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

void dfs(int cx, int cy) {
    for (int i = 0; i < 8; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || ny < 0 || nx >= x || ny >= y)
            continue ;
        if (visit[ny][nx] == true || map[ny][nx] == false)
            continue ;
        visit[ny][nx] = true;
        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        int cnt = 0;

        cin >> x >> y;

        if (x == 0 && y == 0)
            return 0;

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (visit[i][j] == false && map[i][j] == true) {
                    visit[i][j] = true;
                    dfs(j, i);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        
        for (int i = 0; i < y; i++) {
            fill(visit[i], visit[i] + x, false);
            fill(map[i], map[i] + x, false);
        }
    }
    
    return 0;
}