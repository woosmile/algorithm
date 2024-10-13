#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define X second
#define Y first

using namespace std;

int n, m;
int board[10][10];
int board_copy[10][10];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vector< pair<int, int> > empty_vec;
queue< pair<int, int> > virus_q;

int ans;

void bfs() {
    queue< pair<int, int> > virus_q_copy(virus_q);
    
    while(!virus_q_copy.empty()) {
        pair<int, int> cur = virus_q_copy.front();
        virus_q_copy.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue ;
            if (board_copy[ny][nx] != 0)
                continue ;
            board_copy[ny][nx] = 2;
            virus_q_copy.push({ny, nx});
        }
    }
}

void check_empty_space() {
    int cnt = 0;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board_copy[y][x] == 0)
                cnt++;
        }
    }

    ans = max(cnt, ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];

            if (board[y][x] == 0) {
                empty_vec.push_back({y, x});
            }
            else if (board[y][x] == 2) {
                virus_q.push({y, x});
            }
        }
    }

    vector<int> brute(empty_vec.size());
    fill(brute.end() - 3, brute.end(), 1);

    do {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                board_copy[y][x] = board[y][x];
            }
        }
        
        for (int i = 0; i < brute.size(); i++) {
            if (brute[i] == 1) {
                pair<int, int> wall = empty_vec[i];
                board_copy[wall.Y][wall.X] = 1;
            }
        }

        bfs();
        check_empty_space();
        
    } while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
    
    return 0;
}