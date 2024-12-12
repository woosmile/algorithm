#include <iostream>
#include <algorithm>

using namespace std;

int a[505][505];

// 테이블 : 삼각형의 가장 위인 (1,1)에서 시작해서 가장 밑인 (n,n)까지 내려오면서 점화식에 따라서 누적한 수
int dp[505][505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];  // 초기값

    // 이전 행(i - 1)에서 대각선 좌(j - 1), 우(j) 두가지 중에서 가장 큰 값에 현재 값 a[i][j]를 더함
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }

    // n번째 행이 마지막이므로 이 행에서 가장 큰 값을 출력함
    cout << *max_element(dp[n] + 1, dp[n] + n + 1);
    
    return 0;
}