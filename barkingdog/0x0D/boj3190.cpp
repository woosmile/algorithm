#include <iostream>
#include <deque>

#define X second
#define Y first

using namespace std;

int n, k, l;
deque< pair<int, int> > snake;
int board[110][110];
char rotate[10010];
int cnt;

int dx[4] = {1, 0, -1, 0};  // 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1};

bool check_end(int nx, int ny) {
    // if (snake.size() == 1)
    //     return false;
    if (nx < 1 || ny < 1 || nx > n || ny > n)
        return true;
    deque< pair<int, int> > temp = snake;
    while(!temp.empty()) {
        pair<int, int> cur = temp.front();
        temp.pop_front();
        if (cur.X == nx && cur.Y == ny)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        board[y][x] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;
        char c;
        cin >> t >> c;
        rotate[t] = c;
    }

    int dir = 0;
    snake.push_front({1, 1});
    
    while (1) {
        if (rotate[cnt] == 'L')
            dir = (dir + 3) % 4;
        else if (rotate[cnt] == 'D')
            dir = (dir + 1) % 4;
        cnt++;
        pair<int, int> cur = snake.front();
        
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
    
        if (check_end(nx, ny))
            break ;

        if (board[ny][nx] == 1) {
            board[ny][nx] = 0;
            snake.push_front({ny, nx});
        }
        else {
            snake.pop_back();
            snake.push_front({ny, nx});
        }
    }

    cout << cnt;
    
    return 0;
}
