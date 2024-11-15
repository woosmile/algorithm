#include <bits/stdc++.h>

using namespace std;

int n;
int d[1005][3];  // d[집위치][색];
int r[1005], g[1005], b[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }
    
    d[1][0] = r[1];  // 첫번째 집의 R, G, B 최소값
    d[1][1] = g[1];
    d[1][2] = b[1];

    for (int i = 2; i <= n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];  // 이전 집에 색칠한 G, B 중 최소값에 R값을 더함
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];  // 이전 집에 색칠한 R, B 중 최소값에 G값을 더함
        d[i][2] = min(d[i - 1][1], d[i - 1][0]) + b[i];  // 이전 집에 색칠한 G, R 중 최소값에 B값을 더함
    }

    cout << min({d[n][0], d[n][1], d[n][2]});  // 
    
    return 0;
}