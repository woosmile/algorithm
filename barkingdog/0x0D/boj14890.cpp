#include <iostream>
#include <vector>

using namespace std;

int n, l;
int board[105][105];

int cnt;

bool check(vector<int>& line)
{
    int idx = 0;
    int same_len = 1;  // 현재 보고 있는, 높이가 같은 구간의 길이
    
    while (idx < n - 1) {
        if (abs(line[idx] - line[idx + 1]) > 1)
            return 0;
        if (line[idx] == line[idx + 1])
        {
            same_len++;
            idx++;
        }
        else if (line[idx] < line[idx + 1])
        {
            if (same_len < l)
                return 0;
            same_len = 1;
            idx++;
        }
        else
        {
            if (idx + l >= n)
                return 0;
            for (int i = idx + 1; i < idx + l; i++) {
                if (line[i] != line[i + 1])
                    return 0;
            }

            // 경사로를 설치했으면, 설치한 칸부터 다음칸과 비교하므로 same_len을 0으로 둠
            same_len = 0;
            idx = idx + l;
        }
    }
    
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    for (int x = 0; x < n; x++) {
        vector<int> line;
        for (int y = 0; y < n; y++) {
            line.push_back(board[y][x]);
        }
        cnt = cnt + check(line);
    }

    for (int y = 0; y < n; y++) {
        vector<int> line;
        for (int x = 0; x < n; x++) {
            line.push_back(board[y][x]);
        }
        cnt = cnt + check(line);
    }

    cout << cnt;
    
    return 0;
}